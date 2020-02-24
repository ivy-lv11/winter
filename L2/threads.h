#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

struct thread {
  int id;
  pthread_t thread;//int线程号POSIX thread API中的线程号
  void (*entry)(int);//函数指针，回调函数
  struct thread *next;//下一个线程  
};

struct thread *threads;//单链表的头
void (*join_fn)();//函数指针，指向参数表空，返回值void的函数

// ========== Basics ==========
//单链表遍历。把threads链表中的所有线程完成
__attribute__((destructor)) static void join_all() {
  for (struct thread *next; threads; threads = next) {
    pthread_join(threads->thread, NULL); 
    next = threads->next;
    free(threads);
  }
  join_fn ? join_fn() : (void)0;
}

static inline void *entry_all(void *arg) {
  struct thread *thread = (struct thread *)arg;
  thread->entry(thread->id);//thread->entry是回调函数，用thread->id作为参数,进行调用运行
  return NULL;
}

static inline void create(void *fn) {
  struct thread *cur = (struct thread *)malloc(sizeof(struct thread));//分配内存大小
  assert(cur);//假设内存分配成功，如果不成功返回NULL
  cur->id    = threads ? threads->id + 1 : 1;//线程号，空=1，否则+1
  cur->next  = threads;//在头部插入
  cur->entry = (void (*)(int))fn;//强制类型转化，就和int x = (int)y;一样 void (*)(int)是指向函数的指针，参数是int，返回值是void
  threads    = cur;
  pthread_create(&cur->thread, NULL, entry_all, cur);//GNU 
}

//atexit() 可移植
//先把所有线程执行完，最后执行fn
static inline void join(void (*fn)()) {
  join_fn = fn;
}

// ========== Synchronization ==========

#include <stdint.h>

intptr_t atomic_xchg(volatile intptr_t *addr,
                               intptr_t newval) {
  // swap(*addr, newval);
  intptr_t result;
  asm volatile ("lock xchg %0, %1":
    "+m"(*addr), "=a"(result) : "1"(newval) : "cc");
  return result;
}

intptr_t locked = 0;

static inline void lock() {
  while (1) {
    intptr_t value = atomic_xchg(&locked, 1);
    if (value == 0) {
      break;
    }
  }
}

static inline void unlock() {
  atomic_xchg(&locked, 0);
}

#include <semaphore.h>

#define P sem_wait
#define V sem_post
#define SEM_INIT(sem, val) sem_init(&(sem), 0, val)

#include "threads.h"
#include <stdio.h>
//定义自旋锁的数据结果，只有一个变量locked
typedef struct spinlock {
  intptr_t locked;
} spinlock_t;
//初始化锁
void spin_init(spinlock_t *lk) {
  lk->locked = 0;
}
//用xchg上锁
void spin_lock(spinlock_t *lk) {
  while (atomic_xchg(&lk->locked, 1)) ;
}

void spin_unlock(spinlock_t *lk) {
  atomic_xchg(&lk->locked, 0);
}

spinlock_t lk;

int volatile sum = 0;

void do_sum() {
  for (int i = 0; i < 1000000; i++) {
    spin_lock(&lk);//用锁保护我们的临界区
    sum++;
    spin_unlock(&lk);
  }
}

void print() {
  printf("sum = %d\n", sum);
}

int main() {
  spin_init(&lk);
  for (int i = 0; i < 4; i++) {
    create(do_sum);
  }
  join(print);
}

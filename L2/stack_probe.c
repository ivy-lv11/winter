#include "threads.h"
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
__thread char *base, *now; // thread-local variables 线程独享

void set_base(char *ptr) { base = ptr; } 
void set_now(char *ptr)  { now = ptr; }
void *get_base() { return &base; }
void *get_now() { return &now; }

void stackoverflow(int n) {
  putchar('\0'); // some random delays
  char x;//栈里
  if (n == 0) set_base(&x);//大致确定栈起始位置
  set_now(&x);
  if (n % 1024 == 0) {
    printf("[%ld] Stack size @ n = %d: %lx +%ld KB\n",
      syscall(SYS_gettid), n, (intptr_t)base, (base - now) / 1024);//栈向低地址长
  }
  stackoverflow(n + 1);
}

void probe() {
  stackoverflow(0);
}

int main() {
  setbuf(stdout, NULL);
  for (int i = 0; i < 4; i++) {
    create(probe);
  }
  join(NULL);
}

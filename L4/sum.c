#include "threads.h"
#include <stdio.h>
#define PREFIX

long sum;

void do_sum() {
  for (int i = 0; i < 10000000; i++) {
    lock();
	asm volatile(PREFIX "addq $1, %0": "=m"(sum));
	unlock();
  }

  
}

void print() {
  printf("sum = %ld\n", sum);
}

int main() {
  for (int i = 0; i < 4; i++) 
    create(do_sum);
  join(print);
}

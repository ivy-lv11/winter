#include "threads.h"
#include <stdio.h>


char compare_and_swap(int *ptr, int old, int new) {
    unsigned char ret;
    // Note that sete sets a ’byte’ not the word
    __asm__ __volatile__ (
	" lock\n"
	" cmpxchgl %2,%1\n"
	" sete %0\n"
	: "=q" (ret), "=m" (*ptr)
	: "r" (new), "m" (*ptr), "a" (old)
	: "memory");
    return ret;
}

typedef struct lock{
	int flag;
} lock_t;

lock_t lk;

void Lock(lock_t* lk)
{
	while(compare_and_swap(&lk->flag,0,1))
		;
}

void Unlock(lock_t* lk)
{
	lk->flag = 0;
}

void Lock_init(lock_t* lk)
{
	lk->flag = 0;
}

long sum = 0;

void do_sum()
{
	Lock(&lk);
	for(int i=0;i<10000000;i++)
	{
		
		sum++;
	
	}
	Unlock(&lk);
}

void print()
{
	printf("sum = %ld\n",sum);
}

int main()
{
	Lock_init(&lk);
	for(int i=0;i<4;i++)
		create(do_sum);
	join(print);
	return 0;
}

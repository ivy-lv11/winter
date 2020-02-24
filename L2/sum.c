#include "threads.h"
#include <stdio.h>


int sum = 0;
void do_sum()
{
	for (int i=0;i<1000000;i++)
		sum++;
}

void print()
{
	printf("sum = %d\n",sum);
}

int main()
{
	create(do_sum);
	create(do_sum);
	join(print);
}

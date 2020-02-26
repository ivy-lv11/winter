#include "threads.h"
#include <stdio.h>


int x = 0;
int y = 0;

void a()
{
	x = 1;
	printf("y %d\n",y);
}

void b()
{
	y = 1;
	printf("x %d\n",x);
}

int main()
{
	create(a);
	create(b);
}

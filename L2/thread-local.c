#include "threads.h"
#include <stdio.h>


int x = 0;
int y = 0;

void a()
{
//	x = 1;
	printf("a thread\n");
}

void b()
{
//	y = 1;
	printf("b thread\n");
}

int main()
{
	printf("start\n");
	create(a);
	create(b);
	join(b);
	join(a);
	printf("end\n");
}

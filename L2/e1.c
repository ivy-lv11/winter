#include "threads.h"

void a()
{
	while(1)
	{
		printf("a");
	}
}

void b()
{
	while(1)
	{
		printf("b");
	}
}

int main()
{
	create(a);
	create(b);
	return 0;
}

//pthread_create();

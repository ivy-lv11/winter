#include <stdlib.h>
#include <stdio.h>
#include "threads.h"

void hello()
{
	printf("hello\n");
}

int main(int argc, char* argv[])
{
	printf("start\n");
	atexit(&hello);
	return 0;
}

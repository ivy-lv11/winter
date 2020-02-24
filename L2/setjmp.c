#include <setjmp.h>
#include <stdio.h>

jmp_buf env;
int f(int n)
{
	if (n>=8)
		longjmp(env,n);
	printf("jmp to %d\n",n);
	f(n+1);
}

int ain(){
	int r = setjmp(env);
	if (r==0)
	{
		f(1);
	}
	else
	{
		printf("reach %d\n",r);
	}
}

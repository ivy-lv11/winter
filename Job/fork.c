#include <stdio.h>
#include <unistd.h>

extern char** environ;
int main()
{

	int r = fork();
	if(r==0)
		printf("parent\n");
	else
	{
		char* args[] = {"strace","-T","ls",NULL,};
		char** env = environ;
		execve("/usr/bin/strace",args,env);
	}
	return 0;

}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

int main()
{
	int pipes[2];
	int check = pipe(pipes);
	if(check==-1)
		assert(0);
	int pid = fork();
	if(pid==0)
	{
		//child
		dup2(pipes[1],1);

		close(pipes[0]);
		close(pipes[1]);
		
		printf("call from child\n");
	}
	else
	{
		wait(NULL);
		printf("in parent\n");
		dup2(pipes[0],0);
		close(pipes[0]);
		close(pipes[1]);
//		dup2(pipes[1],0);
		char buf[1024];
		fgets(buf,1024,stdin);
		printf("%s\n",buf);
	}
	return 0;
}

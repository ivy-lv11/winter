#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main()
{
	int fd = open("./a.txt",O_RDONLY);
	int pid = fork();
	if(pid==0)
	{
		printf("child: seek at offset 10\n");
		lseek(fd,10,SEEK_SET);
	}
	else
	{
		wait(NULL);
		printf("now at %d\n",(int)lseek(fd,0,SEEK_CUR));
	}
	return 0;
}

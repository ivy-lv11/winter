#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void handle(int sig)
{
	switch(sig)
	{
		case SIGINT:
			printf("receive intr\n");
			break;
		case SIGQUIT:
			printf("quit\n");
			exit(0);
	}
}

void bye()
{
	printf("bye\n");
}
int main()
{
signal(SIGINT,handle);
signal(SIGQUIT,handle);
atexit(bye);

	char str[1024];
	while(1)
	
	{
		fscanf(stdin,"%s",str);
		printf("%s\n",str);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int create()
{
	int fd = open("/home/lv/winter/winter/file-system/a.txt",O_RDONLY,S_IRUSR|S_IWUSR);
	printf("the fd is %d\n",fd);
	char str[10];
	read(fd,str,3);
	printf("%s\n",str);
	read(fd,str,3);
	printf("%s",str);
	lseek(fd,-5,SEEK_END);
	read(fd,str,5);
	printf("%s",str);
	return fd;
}



int main()
{
	int fd = create();
	return 0;
}

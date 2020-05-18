#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
int main()
{
	DIR* dir  = opendir(".");
	struct dirent* ptr;
	while((ptr = readdir(dir))!=NULL)
	{
		printf("%s\n",ptr->d_name);
	}
	closedir(dir);
	return 0;
}

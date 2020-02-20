#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>



int main(){
	DIR* dir_ptr;
	struct dirent *direntp;
	dir_ptr = opendir("/home/lv/vsc/dd");
	if (dir_ptr==NULL)
	{
		fprintf(stderr,"error");
	}
	else
	{
//		direntp = readdir(dir_ptr);
//		if (direntp!=NULL)
//			printf("%s\n",direntp->d_name);
		while((direntp = readdir(dir_ptr))!=NULL)
		{
	//		printf("name\n");
			if (direntp->d_name[0]>='0' && direntp->d_name[0]<='9')
			{
				printf("%s\n",direntp->d_name);
				char path[200];
				strcpy(path,"/home/lv/vsc/dd/");
				strcat(path,direntp->d_name);
			//	printf("%s\n",path);
				strcat(path,"/stat");
		//		printf("%s\n",path);
				FILE *fp = fopen(path,"r");
				printf("a\n");
				if (fp==NULL)
				{
					fprintf(stderr,"error");
				}
				else
				{
					printf("b\n");
					char dump[300];
					char name[20];
					char status[4];
					int num;
					int parent_id;
					fscanf(fp,"%d (%[^)]) %s %d %s\n",&num,name,status,&parent_id,dump);
					printf("%s\n",name);
		//			int i;
		//			for (i=0;i<strlen(name);i++)
		//				name[i] = name[i+1];
		//			name[strlen(name)-1] = '\0';
					printf("%s(%d):status %s:parent %d\n",name,num,status,parent_id);
					fclose(fp);
				}
				
			}

		}
		closedir(dir_ptr);
	}
	return 0;
}

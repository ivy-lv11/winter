#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
int is_prime(int x)
{
	for (int i=2;i<=(int)sqrt(x);i++)
	{
		if (x%i==0)
			return 0;
	}
	return 1;
}

int main(int argc,char *argv[])
{
	int opt;
	int n;
	while((opt = getopt(argc,argv,"n:"))!=-1)
	{
		if (opt=='n')
		{
			n = atoi(optarg);	
		}
	}

//	int n;
//	scanf("%d",&n);
	int *p = malloc(sizeof(int)*n);
	int count = 0;
	for (int i=2;i<n;i++)
	{
		if (is_prime(i)==1)
		{	p[count] = i;
			count++;
		}
	}

	for (int i=0;i<count;i++)
		printf("%d\n",p[i]);
	return 0;
}

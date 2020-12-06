#include "ch09.h"
int main(int argc,char **argv)
{
	int i;
	printf("test : pid =%d,ppid=%d\n",getpid(),getppid());
	for(i=0;i<argc;i++)
	{
		printf("argv[%d] :%s\n",i,argv[i]);
	}
	//sleep(40);

	return 0;

}

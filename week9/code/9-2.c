#include "ch09.h"
//使用execve函数来调用test
int main()
{
	char *argv[]={"./test","hello","world",NULL};
	int i;
	printf("9-2 :pid = %d,ppid =%d \n",getpid(),getppid());
	i = execve("./test",argv,NULL);
	if(i==-1)
	{
		perror("execve failed!!! \n");
		exit(1);
	}

	printf("after calling!\n");
	return 0;
}

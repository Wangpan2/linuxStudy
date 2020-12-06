#include "ch09.h"
//错误逻辑，不能完成只派生两个子进程，因为复制映像会多派生一个
int main()
{
	int r1=99,r2=99;
	r1=fork();
	r2=fork();
	if(r1<0||r2<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(r1==0)
	{
		printf("child 1:pid = %d, ppid =%d,r1= %d,r2 =%d\n",getpid(),getppid(),r1,r2);
		exit(-1);
	} 
	else if(r2==0)
	{
		printf("child 2:pid = %d, ppid =%d,r1= %d,r2 =%d\n",getpid(),getppid(),r1,r2);
		exit(-1);
	}
}

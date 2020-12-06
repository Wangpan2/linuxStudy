#include "ch08.h"
int g=9;
//验证父子进程具有独立空间，对同样变量进行修改互相不影响
int main()
{
	pid_t pid;
	int l=99;
	pid= fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("child: ppid = %d, pid = %d \n",getppid(),getpid());
		printf("child: init g =%d,l=%d\n",g,l);
		g--;
		l++;
		printf("child: g= %d, l= %d \n",g,l);
		exit(0);
	}
	else
	{
		wait(NULL);//子进程先行
		printf("parent: child pid= %d, pid = %d\n",pid,getpid());
		printf("parent: init g =%d,l=%d\n",g,l);
		g++;
		l--;
		printf("parent: g = %d, l = %d \n",g,l);
		return 0;
	}

}

#include "ch08.h"
int g=9;
//验证vfork(),父子进程共享空间，子进程只有exec族函数调用时才分配内存
int main()
{
	pid_t pid;
	int l=99;
	pid= vfork();
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
		printf("vfork--child: g= %d, l= %d \n",g,l);
		return 0;
		//_exit(0);
	}
	else
	{
		wait(NULL);
		printf("parent: child pid= %d, pid = %d\n",pid,getpid());
		printf("parent: init g =%d,l=%d\n",g,l);
		g--;
		l++;
		printf("after vfork--parent: g = %d, l = %d \n",g,l);
		return 0;
	}

}

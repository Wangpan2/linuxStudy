#include "ch09.h"
//使用fork,exec,wait来测试system函数
int main()
{
	pid_t r1;
	r1=fork();
	if(r1<0)
	{
		perror("fork failed!!\n");
	}
	else if(r1==0)
	{
		char *argv[]={"./test","hello","world",NULL};
		int i;
		printf("9-7 :pid = %d,ppid =%d ,r1=%d\n",getpid(),getppid(),r1);
		i = execve("./test",argv,NULL);
		
		if(i==-1)
		{
			perror("execve failed!!! \n");
			exit(1);
		}

		printf("after calling!\n");
		exit(99);
		//return 0;
	}
	else
	{
		int s,r;
		r=wait(&s);
		printf("exit code = %d,wait pid = %d\n",WEXITSTATUS(s),r);
		return 0;
		//wait(NULL);
	}
}

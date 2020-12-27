#include "ch10.h"
//使用fork,exec,wait来测试system函数
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!!\n");
	}
	else if(pid==0)
	{
		char *argv[]={"./test","hello","world",NULL};
		int i;
		printf("9-7 :pid = %d,ppid =%d ,r1=%d\n",getpid(),getppid(),pid);
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
		if(WIFEXITED(s))//正常退出
		{
			printf("exit code = %d,wait pid = %d\n",WEXITSTATUS(s),r);
		}
		else
		{
			//printf("child process stoped unnormaly!\n");
			printf("child process stoped with signal %d!!\n",WTERMSIG(s));
		}

	
		return 0;
		//wait(NULL);
	}
}

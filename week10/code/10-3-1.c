#include "ch10.h"
//测试waitpid
int main()
{
	pid_t pid1;
	pid1=fork();//派生第一个子进程
	if(pid1<0)
	{
		perror("fork failed!!\n");
		exit(-1);
	}
	else if(pid1==0)
	{
		char *argv[]={"./test","hello","world",NULL};
		
		printf("child1 :pid = %d,ppid =%d ,re=%d\n",getpid(),getppid(),pid1);
		execve("./test",argv,NULL);
				
		//exit(99);
		exit(0);
		//return 0;
	}
	else
	{
		pid_t pid2;
		pid2=fork();//派生第二个子进程
		if(pid2<0)
		{
			perror("fork failed!!\n");
		}
		else if(pid2==0)
		{
			printf("child2 :pid = %d,ppid =%d ,r1=%d\n",getpid(),getppid(),pid2);
			
			for(int i=0;i<9;i++)
			{
				printf("%d :Hello!\n",i);
				//exit(99);
				exit(0);
			}
			
			
			/*int i;
			while(1)//让第二个子进程不停止
			{
				printf("%d :HEllo!\n",i++);
			}
			exit(0);*/

		}
		else
		{

		
			int s1,r1,s2,r2;
			//r1=wait(&s1);
			//r2=wait(&s2);
			//r1=waitpid(pid1,&s1,NULL);
			//r2=waitpid(pid2,&s2,NULL);

			r1=waitpid(pid1,&s1,WNOHANG);
			r2=waitpid(pid2,&s2,WNOHANG);
			if(r2==0)
			{
				printf("r2 have no end!\n");
			}
			else
			{
				printf("child 2 exit normally! exit code = %d\n",WEXITSTATUS(s2));
			}
			if(r1==0)
			{
				printf("child1 have no end!\n");
			}
			else
			{
				printf("child 1 exit normally! exit code = %d\n",WEXITSTATUS(s1));
			}

			/*if(WIFEXITED(s1))//正常退出
			{
				printf("child 1 exit normally! exit code = %d",WEXITSTATUS(s1));
			}
			else 
			{
				printf("child 1 process abmomaly! stoped with signal %d!!\n",WTERMSIG(s1));
			}

			if(WIFEXITED(s1))//正常退出
			{
				printf("child 2 exit normally! exit code = %d",WEXITSTATUS(s1));
			}
			else 
			{
				printf("child 2 process abmomaly! stoped with signal %d!!\n",WTERMSIG(s1));
			}*/

			return 0;			

		}

		
		return 0;
		//wait(NULL);
	}
}

#include "ch10.h"
//测试三个子进程情况下的wait
int main()
{
	pid_t pid1;
	pid1=fork();
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
		pid2=fork();
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

		}
		else
		{

			pid_t pid3;
			pid3=fork();
			if(pid3<0)
			{
				perror("fork failed!!\n");
			}
			else if(pid3==0)
			{
				printf("child3 :pid = %d,ppid =%d ,r1=%d\n",getpid(),getppid(),pid2);
				
			}
			else{
				int s1,r1,s2,r2,s3,r3;
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				if(r1==pid1)
				{
					printf("child 1 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
				}
				else if(r1==pid2)
				{
					printf("child 1 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
				}
				else if(r1==pid3)
				{
					printf("child 1 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
				}

				if(r2==pid1)
				{
					printf("child 2 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
				}
				else if(r2==pid2)
				{
					printf("child 2 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
				}
				else if(r2==pid3)
				{
					printf("child 2 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
				}

				if(r3==pid1)
				{
					printf("child 3 %d is exited! exit code %d\n",r3,WEXITSTATUS(s3));
				}
				else if(r3==pid2)
				{
					printf("child 3 %d is exited! exit code %d\n",r3,WEXITSTATUS(s3));
				}
				else if(r3==pid3)
				{
					printf("child 3 %d is exited! exit code %d\n",r3,WEXITSTATUS(s3));
				}


		
/*				if(WIFEXITED(s1))//正常退出
				{
					printf("exit code = %d,wait pid = %d\n",WEXITSTATUS(s1),r1);
				}
				else
				{
					printf("child process stoped with signal %d!!\n",WTERMSIG(s1));
				}
*/

				return 0;

			}

		}

		
		return 0;
		//wait(NULL);
	}
}

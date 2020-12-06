#include "ch09.h"
//一个父进程派生三个子进程，第三个子进程又派生出两个子进程
int main()
{
	int r1,r2,r3,r4,r5;
	r1=fork();//派生第一个子
	if(r1<0)
	{
		perror("fork failed!!");
		exit(-1);	
	}
	if(r1==0)
	{
		printf("child 1:pid = %d,ppid = %d\n",getpid(),getppid());
		exit(0);
	}
	if(r1>0)
	{
		r2 = fork();//派生第二个子
		if(r2<0)
		{
			perror("fork failed!!");
			exit(-1);	
		}
		if(r2 == 0)
		{
			printf("child 2: pid =%d, ppid = %d\n",getpid(),getppid());
			r4=fork();//派生第一个孙子
			if(r4<0)
			{
				perror("fork failed!!");
				exit(-1);	
			}
			if(r4==0)
			{
				printf("grandson1 : pid =%d, ppid = %d\n",getpid(),getppid());
				exit(0);
			}
			if(r4>0)
			{
				r5=fork();//派生第二个孙子
				if(r5<0)
				{
					perror("fork failed!!");
					exit(-1);	
				}
				if(r5==0)
				{
				printf("grandson2: pid =%d, ppid = %d\n",getpid(),getppid());
				exit(0);
				}
				wait(NULL);//等待任意一个子进程结束
				wait(NULL);
				printf("grandson-parent :pid = %d ,r4 = %d, r5 =%d\n",getpid(),r4,r5);
			}
		}
		if(r2>0)
		{
			r3=fork();//派生第三个子
			if(r3==0)
			{
				printf("child 3: pid = %d,ppid= %d\n",getpid(),getppid());
				exit(0);
			}
			wait(NULL);//等待任意一个子进程结束
			wait(NULL);
			wait(NULL);
			printf("parent :pid = %d ,r1 = %d, r2 =%d\n",getpid(),r1,r2);
			return 0;
		}
		
	}

}

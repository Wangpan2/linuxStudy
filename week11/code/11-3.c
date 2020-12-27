//派生两个子进程互相通信
#include "ch11.h"
int main()
{
	int fd1[2],fd2[2],i;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pid_t pid1;
	pipe(fd1);// 生成管道
	pipe(fd2);
	pid1=fork();
	if(pid1<0)
	{
		perror("fork failed!!\n");
		exit(-1);
	}
	else if(pid1==0)//派生第一个子进程
	{	
		close(fd1[1]);
		close(fd2[0]);
		sleep(1);
		i=read(fd1[0],buf,sizeof(buf));//读缓冲区中内容的实际大小
		if(i==0)
		{
			printf("child1 read failed!\n");
			exit(0);
		}
		else
		{
			fprintf(stdout,"child1 read from child2 : %s,%d \n",buf,strlen(buf));
			sprintf(buf,"child1 receive from child2 %d bytes!\n",strlen(buf));
			write(fd2[1],buf,sizeof(buf));
			
			exit(1);
		}
	}
	else
	{
		pid_t pid2;
		pid2=fork();
		if(pid2<0)
		{
			perror("fork failed!!\n");
			exit(-1);
		}
		else if(pid2==0)//派生第二个子进程
		{
			close(fd1[0]);
			close(fd2[1]);
			sprintf(buf,"child2  say hello to child1\n ");
			i=write(fd1[1],buf,sizeof(buf));
			if(i==0)
			{
				printf("parent write failed!\n");

			}
			else
			{
				printf("write to pipe : %s\n",buf);

			}
			read(fd2[0],buf,sizeof(buf));
			printf(" %s \n",buf);

		}
		else
		{
			int s1,r1,s2,r2;
			r1=waitpid(pid1,&s1,0);//死等
			r2=waitpid(pid2,&s2,0);
		}
		return 0;
		//wait(NULL);
	}
}

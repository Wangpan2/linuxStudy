#include "ch11.h"
//父子进程双向通信
int main()
{
	int fd[2],i;
	int fd1[2];
	char buf[100];
	memset(buf,0,sizeof(buf));
	pid_t k;
	
	pipe(fd);//生成管道
	pipe(fd1);
	k=fork();//派生子进程
	if(k<0)
	{
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd[1]);//关闭写文件
		sleep(1);
		i=read(fd[0],buf,sizeof(buf));
		if(i==0)
		{
			printf("child read failed!\n");
			exit(0);
		}
		else
		{
			fprintf(stdout,"read from pipe : %s\n",buf);
			exit(1);
			//儿子发送
			close(fd1[0]);//关闭读
			menset(buf,0,sizeof(buf));
			i=write(fd1[1],buf,sizeof(buf));
			if(i==0)
			{
				printf("child write failed!\n");
			}
			else
			{
				printf("child has received %d \n",sizeof(buf));
			}
		}
	}
	else
	{
		close(fd[0]);
		
		sprintf(buf,"%d  say hello to %d! ",getpid(),k);
		i=write(fd[1],buf,sizeof(buf));
		if(i==0)
		{
			printf("parent write failed!\n");

		}
		else
		{
			printf("write to pipe : %s\n",buf);
		}
		close(fd1[1]);
		i=read(fd[0],buf,sizeof(buf));

	
		wait(NULL);

		
		exit(0);
	}
}

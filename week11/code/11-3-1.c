//子进程间相互通信,正确版
#include "ch11.h"
int main()
{
	int fd1[2],fd2[2];
	char buf[100];
	memset(buf,0,sizeof(buf));
	pipe(fd1);
	pipe(fd2);
	pid_t k1,k2;
	k1=fork();
	if(k1<0)
	{
		perror("fork1 failed!\n");
		exit(-1);
	}
	else if(k1==0)
	{
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"k1 parent = %d : %d send message!\n",getppid(),getpid());
		write(fd1[1],buf,sizeof(buf));
		read(fd2[0],buf,sizeof(buf));
		printf("k1 %d receive %s \n",getpid(),buf);
		exit(0);
	}
	else
	{
		k2=fork();
		if(k2<0)
		{
			perror("fork2 failed!\n");
			exit(-1);
		}
		else if(k2==0)
		{
			close(fd1[1]);
			close(fd2[0]);
			read(fd1[0],buf,sizeof(buf));//读第一个管道到buf
			printf("k2 %d receive %s \n",getpid(),buf);//输出从第一个管道接收的消息
			
			sprintf(buf,"k2 parent = %d :%d send message!\n",getppid(),getpid());
			write(fd2[1],buf,sizeof(buf));//将缓冲buf写入第二个管道
			
			exit(0);
		}
		else
		{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);
			wait(NULL);
			wait(NULL);
		}	

	}

}

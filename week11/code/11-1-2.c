#include "ch11.h"
//父子进程双向通信
int main()
{
	int fd1[2],fd2[2],i;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pid_t k;
	
	pipe(fd1);//生成管道
	pipe(fd2);
	k=fork();//派生子进程
	if(k<0)
	{
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd1[1]);
		close(fd2[0]);
		sleep(1);
		i=read(fd1[0],buf,sizeof(buf));//读缓冲区中内容的实际大小
		if(i==0)
		{
			printf("child read failed!\n");
			exit(0);
		}
		else
		{
			fprintf(stdout,"read from pipe : %s ,%d\n",buf,strlen(buf));
			
			sprintf(buf,"child receive from parent %d bytes!\n",strlen(buf));
			write(fd2[1],buf,sizeof(buf));
			/*if((write(fd2[1],buf,sizeof(buf)))<=0)
			{
				perror("child write error!\n");

			}
			else
			{
				printf("child write success!i=%d\n",i);
			}*/
			exit(1);
		}
	}
	else
	{
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"%d  say hello to %d! ",getpid(),k);
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
		wait(NULL);
		exit(0);
	}
}

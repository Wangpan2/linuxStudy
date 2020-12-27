#include "ch11.h"
//父子进程单向通信
int main()
{
	int fd[2],i;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pid_t k;
	
	pipe(fd);//生成管道
	k=fork();//派生子进程
	if(k<0)
	{
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd[1]);
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
		wait(NULL);
		exit(0);
	}
}

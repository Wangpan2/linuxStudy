#include "ch08.h"

int main()
{
	int fd_out;
	char buf[1024];
	pid_t pid1,pid2;

	memset(buf,0,1024);
	
	fd_out = open(OUTFILE,O_WRONLY|O_CREAT|O_TRUNC,MODE);

	if(fd_out<0)
	{
		fprintf(stderr,"failed to open %s,reason(%s)\n",OUTFILE,strerror(errno));
	}

	pid1= fork();
	if(pid1<0)
	{
		fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));

		return 1;
	}
	else if(pid1==0)//派生第一个子进程
	{
		sprintf(buf,"1th son:%d time:%d\n",getpid(),time(NULL));
		write(fd_out,buf,strlen(buf));
		sleep(1);
		memset(buf,0,1024);
	}

	pid2= fork();
	if(pid2<0)
	{
		fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));

		return 1;
	}
	else if(pid2 ==0)//派生第二个子进程
	{
		sprintf(buf,"2th son:%d time:%d\n",getpid(),time(NULL));
		write(fd_out,buf,strlen(buf));
		sleep(1);
		memset(buf,0,1024);
	}



}


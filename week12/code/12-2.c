#include "ch12.h"

int main()
{
	int fifo_fd,n,i,total_bytes=0;
	char sendbuf[PIPE_BUF];
	
	/*if(access(FIFO_FILE,F_OK)==-1)
	{
		if(mkfifo(FIFO_FILE,06666)!=0)
		{
			printf("Could not create fifo %s \n",FIFO_FILE);
			exit(-1);
		}
	}*/
	
	if((fifo_fd=open(FIFO_FILE,O_WRONLY))<0)
	{
		printf("Could not open fifo %s\n",FIFO_FILE);
		exit(-1);
	}
	printf("Process %d 's child %d opened :%s \n",getppid(),getpid(),FIFO_FILE);
	
	do
	{
		if((n=write(fifo_fd,sendbuf,PIPE_BUF))==-1)
		{
			perror("Write failed!\n");
			exit(-1);
		}
		printf("%d write %d bytes \n",getpid(),n);
		total_bytes+=n;
	}while(total_bytes<TEN_MEG);
	/*while((n=read(fifo_fd,readbuf,PIPE_BUF))>0)
	{
		printf("%d received %d bytes \n",getpid(),n);
		total_bytes+=n;
	}*/
	close(fifo_fd);
	printf("Process %d received %d bytes \n",getpid(),total_bytes);
	return 0;


}

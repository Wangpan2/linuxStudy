//子进程间相互通信,通过父进程转发,并记录在文件中
#include "ch11.h"
//写时间函数

char buf[1024];
int fd_in, fd_out;
int w_Time(pid_t pid){
	int i;
	struct timeval time_v;
	struct timezone time_z;
	struct tm * t;
	gettimeofday(&time_v, &time_z);
	t = localtime(&time_v.tv_sec);
	memset(buf, 0, 1024);
	int ret = sprintf(buf,"pid: %d--send time: %d/%d/%d %d:%d:%d.%ld\n", pid,t->tm_year+1900, 1+t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, time_v.tv_usec);
	//printf("%s",buf);	
	i=write(fd_out, buf, strlen(buf));
	if(i==0)
	{
		printf("failed!");
	}
	memset(buf, 0, 1024);
	return ret;
}

int main()
{
	//打开文件
	fd_in = open(INFILE, O_WRONLY|O_CREAT|O_TRUNC, MODE);
	if(fd_in < 0){
		fprintf(stderr, "failed to open %s, reason(%s)\n", INFILE, strerror(errno));
		return 1;
	}
	
	fd_out = open(OUTFILE, O_WRONLY|O_CREAT|O_TRUNC, MODE);
	if(fd_out < 0){
		fprintf(stderr, "failed to open %s, reason(%s)\n", OUTFILE, strerror(errno));
		return 1;
	}


	int fd1[2],fd2[2],fd3[2],fd4[2],r1,r2;
	char buf1[1024],buf2[1024];
	memset(buf1,0,sizeof(buf1));
	memset(buf2,0,sizeof(buf2));
	pipe(fd1);//k1向父进程发消息
	pipe(fd2);//父进程转发给k2
	pipe(fd3);//k2向父进程
	pipe(fd4);//父进程转发给k1

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
		close(fd4[1]);
		close(fd2[0]);
		close(fd2[1]);
		close(fd3[0]);
		close(fd3[1]);
		do{
			/*sprintf(buf1,"k1 parent = %d : %d send message!\n",getppid(),getpid());
			write(fd1[1],buf1,sizeof(buf1));*/
			fflush(stdin);
			memset(buf1,0,sizeof(buf1));
			memset(buf2,0,sizeof(buf2));
			printf("k1 please input the message:");
			fgets(buf1,sizeof(buf1),stdin);
			write(fd1[1],buf1,sizeof(buf1));
			

			read(fd4[0],buf2,sizeof(buf2));
		}while(strcmp(buf1,"88\n")!=0);

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
			close(fd2[1]);
			close(fd3[0]);
			close(fd1[0]);
			close(fd1[1]);
			close(fd4[0]);
			close(fd4[1]);
			
			do{
				read(fd2[0],buf1,sizeof(buf1));
				
				/*sprintf(buf2,"k2 parent = %d :%d send message!\n",getppid(),getpid());
				write(fd3[1],buf2,sizeof(buf2));*/
				fflush(stdin);
				memset(buf1,0,sizeof(buf1));
				memset(buf2,0,sizeof(buf2));
				printf("k2 please input the message:");
				fgets(buf2,sizeof(buf2),stdin);
				write(fd3[1],buf2,sizeof(buf2));//k2消息写给父进程
				
			}while(strcmp(buf2,"88\n")!=0);
			
			exit(0);
		}
		else
		{
			close(fd1[1]);
			close(fd2[0]);
			close(fd3[1]);
			close(fd4[0]);
			
			do{
				if((r1=waitpid(k1,NULL,WNOHANG))==0)//进程未终止
				{
					memset(buf1,0,sizeof(buf1));
					read(fd1[0],buf1,sizeof(buf1));//来自k1的消息读到buf1
					//记录至文件log.dat
					w_Time(k1);
					write(fd_out,buf1,sizeof(buf1));
					

					write(fd2[1],buf1,sizeof(buf1));//父转发k1的消息给k2
				}
				
				if((r2=waitpid(k2,NULL,WNOHANG))==0)
				{
					memset(buf2,0,sizeof(buf2));
					read(fd3[0],buf2,sizeof(buf2));//来自k2的消息读到buf2
					//记录至文件log.dat
					w_Time(k2);
					write(fd_out,buf2,sizeof(buf2));
					

					write(fd4[1],buf1,sizeof(buf1));//父转发k2的消息给k1
				}
			}while(r1==0||r2==0);
			
			//wait(NULL);
			//wait(NULL);
		}	

	}

}

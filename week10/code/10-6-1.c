#include "ch10.h"
//测试waitpid
//写时间函数
char buf[1024];
int fd_in, fd_out;
int w_Time(){
	struct timeval time_v;
	struct timezone time_z;
	struct tm * t;
	gettimeofday(&time_v, &time_z);
	t = localtime(&time_v.tv_sec);
	memset(buf, 0, 1024);
	int ret = sprintf(buf,"\t end time: %d/%d/%d %d:%d:%d.%ld\n", t->tm_year+1900, 1+t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, time_v.tv_usec);	
	write(fd_out, buf, strlen(buf));
	memset(buf, 0, 1024);
	return ret;
}


int main()
{

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

	pid_t pid1;
	pid1=fork();//派生第一个子进程
	if(pid1<0)
	{
		perror("fork failed!!\n");
		exit(-1);
	}
	else if(pid1==0)
	{
		int pid11;
		pid11=fork();//派生第一子的子

		if(pid11<0)
		{
				perror("fork failed!!");
				exit(-1);	
		}
		if(pid11==0)
		{
			printf("child11 : pid11 =%d, ppid = %d,re=%d\n",getpid(),getppid(),pid11);
			
			//第一个儿子的儿子结束时间写入文件
			sprintf(buf, "child11 : pid11: %d  ppid: %d", getpid(), getppid());
			write(fd_out, buf, strlen(buf));
			w_Time();

			exit(0);
		}
		else{
			int r11,s11;
			
			r11=waitpid(pid11,&s11,0);
			printf("child1 :pid = %d,ppid =%d ,re=%d\n",getpid(),getppid(),pid1);
			/*
			char *argv[]={"./test","hello","world",NULL};
			printf("child1 :pid = %d,ppid =%d ,re=%d\n",getpid(),getppid(),pid1);
			execve("./test",argv,NULL);
			*/

			//第一个儿子结束时间写入文件
			sprintf(buf, "child1 : pid1: %d  ppid: %d", getpid(), getppid());
			write(fd_out, buf, strlen(buf));
			w_Time();
		
			//exit(99);
			exit(0);
		}
			
	}
	else
	{
		pid_t pid2;
		pid2=fork();//派生第二个子进程
		if(pid2<0)
		{
			perror("fork failed!!\n");
			exit(-1);
		}
		else if(pid2==0)
		{
			pid_t pid21;
			pid21=fork();//派生第二个子的子

			if(pid21<0)
			{
					perror("fork failed!!");
					exit(-1);	
			}
			if(pid21==0)
			{
				printf("child21 : pid21 =%d, ppid = %d,re=%d\n",getpid(),getppid(),pid21);

				//把第二个儿子的儿子写入文件
				sprintf(buf, "child21 : pid21: %d  ppid: %d", getpid(), getppid());
				write(fd_out, buf, strlen(buf));
				w_Time();

				exit(0);
			}
			else
			{
				int r21,s21;
			
				r21=waitpid(pid21,&s21,0);
				

				printf("child2 :pid2 = %d, ppid =%d ,re=%d\n",getpid(),getppid(),pid2);
				
				//while(1);//让第二个子进程不停止

				//第二个儿子写入文件
				sprintf(buf, "child2 : pid11: %d  ppid: %d", getpid(), getppid());
				write(fd_out, buf, strlen(buf));
				w_Time();

				exit(0);
			}

		}
		else
		{

		
			int s1,r1,s2,r2;
			//r1=wait(&s1);
			//r2=wait(&s2);
			r1=waitpid(pid1,&s1,0);//死等
			r2=waitpid(pid2,&s2,0);
			

			if(WIFEXITED(s1))//正常退出
			{
				printf("child 1 exit normally! exit code = %d\n",WEXITSTATUS(s1));
				
			}
			else 
			{
				printf("child 1 process abmomaly! stoped with code %d!!\n",WTERMSIG(s1));
			}

			if(WIFEXITED(s2))//正常退出
			{
				printf("child 2 exit normally! exit code = %d\n",WEXITSTATUS(s2));
			
			}
			else 
			{
				printf("child 2 process abmomaly! stoped with code %d!!\n",WTERMSIG(s2));
			}
			
			printf("\nparent ended!!\n");

			//父进程结束时写入文件
			sprintf(buf, " parent : pid: %d  ppid: %d", getpid(),getppid());
			write(fd_out, buf, strlen(buf));
			w_Time();

			return 0;			

		}

		
		return 0;
		//wait(NULL);
	}
}

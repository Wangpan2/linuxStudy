#include "ch11.h"
//子进程调用test输入到管道，父进程从管道输出（有点问题）
int main(void)
{
	int pid, fd[2],len;
	char buffer[100];
	    
	if ( pipe(fd) != 0) 
		perror("pipe creation failed");
	if ((pid = fork())== 0) 
	{ 
		close(fd[0]);            
		dup2(fd[1],1); //dup2复制fd[1]到新的文件描述字1（标准输出）          
		close(fd[1]);//关闭这个不再有用的描述字            
		//子进程调用test写入管道       
		char *argv[]={"./test","hello","world",NULL};
		int i;
		printf("child :pid = %d,ppid =%d \n",getpid(),getppid());
		i = execve("./test",argv,NULL);
		if(i==-1)
		{
			perror("execve failed!!! \n");
			exit(1);
		}
	} 
	else 
	{                     
		close(fd[1]);
		//父进程对管道中的test进行读出            
		printf("parent read from pipe and output:\n");
		dup2(fd[0],0);         
		close(fd[0]);
		while (gets(buffer) != NULL)
			puts(buffer);        
	}
 } 

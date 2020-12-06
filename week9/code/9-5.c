#include "ch09.h"
//验证子进程僵尸状态
int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		perror("error fork");
		exit(1);

	}
	else if(pid==0)
	{
		exit(0);
	}
	else
	{
		sleep(300);
		wait(NULL);
	}

	return 0;

}

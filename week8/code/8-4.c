#include "ch08.h"
//测试execve函数
char *env_init[]={"USER=stu","PATH=/tmp",NULL};
int main()
{
	char *args[]={"./test","hello","world!\n",NULL};
	//if(execve("./test",args,NULL)==-1)//最后一个参数为环境变量
	if(execve("./test",args,env_init)==-1)
	{
		perror("execve!\n");
		exit(EXIT_FAILURE);
	}
	puts("Never get here!\n");
	exit(EXIT_SUCCESS);

}

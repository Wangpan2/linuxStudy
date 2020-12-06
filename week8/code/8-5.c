#include "ch08.h"
//测试execle函数
char *env_init[]={"USER=stu","PATH=/tmp",NULL};
int main()
{
	//char *args[]={"./test","hello","world!\n",NULL};
	if(execle("./test","./test","hello","world!\n",(char*)0,env_init)==-1)
	{
		perror("execve!\n");
		exit(EXIT_FAILURE);
	}
	puts("Never get here!\n");
	exit(EXIT_SUCCESS);

}

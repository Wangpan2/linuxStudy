#include "ch06.h"
//使用函数进行获路径的环境变量

/*
int main()
{
	printf("%s \n",getenv("PATH"));
	return 0;

}
*/

//使用系统环境变量指针进行获取
int main()
{
	int i=0;
	extern char **environ;//外部变量的引用
	
	for(i=0;environ[i]!=NULL;i++)
		printf("env[%d]:%s\n",i,environ[i]);
	return 0;

}

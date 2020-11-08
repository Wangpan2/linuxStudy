#include "ch06.h"
//main函数参数打印
int main(int argc,char *argv[])
{
	for(int i=0;i<argc;i++)
	{
		printf("argv[%d]  :%s"，i,argv[i]);

	}
	return;
}


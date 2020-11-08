#include "ch05.h"
//解决没有换行符的行缓冲问题，方法1,使用循环填满一块缓冲区
int main()
{
	int i;
	printf("hello!");
	for(i=0;i<1024;i++)
	{
		printf(" ");	
	}
	while(1);
	return 0;
}

#include "ch05.h"
//解决没有换行符的行缓冲问题，方法3,使用fflush刷新
int main()
{
	
	printf("hello!");
	fflush(stdout);
	while(1);
	return 0;
}

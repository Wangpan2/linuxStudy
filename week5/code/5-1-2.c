#include "ch05.h"
//解决没有换行符的行缓冲问题，方法1,使用setvbuf
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	printf("hello!");
	
	while(1);
	return 0;
}

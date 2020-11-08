#include "ch05.h"
//解决没有换行符的行缓冲问题，方法5,使用setbuf
int main()
{
	//char buf[BUFSIZ];
	printf("hello!");
	setbuf(stdout,NULL);//关闭缓冲区
	while(1);
	return 0;
}

#include "ch05.h"
//解决没有换行符的行缓冲问题，方法4:使用fclose
int main()
{
	
	printf("hello!");
	fclose(stdout);
	while(1);
	return 0;
}

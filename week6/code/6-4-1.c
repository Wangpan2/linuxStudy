#include "ch06.h"
//析构函数--在最后执行，收回对象等清理工作
static void __attribute__((destructor))After_main()
{
	printf("-----------AfterMain----------");
}

//回调函数，清理工作
void callback1()
{
	printf("-----------callback1---------\n");
}

void callback2()
{
	printf("-----------callback2---------\n");
}

void callback3()
{
	printf("-----------callback3---------\n");
}


//用循环测试杀死进程ps -ef
int main()
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	while(1)
	{
		printf("-------program running now!------\n");
	}
	printf("-------program finished-------\n");
	return 0;

}

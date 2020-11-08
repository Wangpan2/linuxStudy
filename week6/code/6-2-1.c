#include "ch06.h"
//构造函数
static void __attribute__((constructor))before_main(void)
{
	printf("--------Before Main-----------------\n");
}
//析构函数
static void __attribute__((destructor))after_main(void)
{
	printf("--------After Main----------------\n");
}

int main()
{
	printf("--------Main Function is Running!---------\n");
}



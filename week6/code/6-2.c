#include "ch06.h"
//构造函数
static void _attribute_((constructor))before_main(void)
{
	printf("--------Before Main-----------------");
}

int main()
{
	printf("--------Main Function is Running!---------\n");
}

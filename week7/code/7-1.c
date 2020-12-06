#include "ch07.h"
//验证进程空间地址分配
static int x1=0,x2;
int y;
int main()
{
	int n=1;
	int x3=0xffffffff,x4;
	static int x5=0x11111111;
	int a[10];
	//int *pt=(int *)malloc(10*sizeof(int));
	//int *pt=(int *)malloc(1024*1024*sizeof(long));
	//int *pt=(int *)malloc(10*1024*1024*sizeof(long));
	int *pt=(int *)malloc(1024*1024*1024*sizeof(long));
	//int *pt=(int *)malloc(65536*65536*65536*65536*sizeof(long));
	
	printf("address of y %x\n",(unsigned int)&y);
	printf("address of x1 %x\n",(unsigned int)&x1);
	printf("address of x2 %x\n",(unsigned int)&x2);
	printf("address of x3 %x\n",(unsigned int)&x3);
	printf("address of x4 %x\n",(unsigned int)&x4);
	printf("address of x5 %x\n",(unsigned int)&x5);
	printf("address of a %x\n",(unsigned int)a);
	
	printf("address of pt %x, %d \n",(unsigned int)pt,sizeof(pt));

	return 0;
}

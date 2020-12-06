#include "ch09.h"
//使用system来调用test
int main()
{
	printf("9-1.c : pid=%d, ppid = %d",getpid(),getppid());
	system("./test hello world 2020 11 23");
	printf("\nafter calling \n");
	return 0;

}

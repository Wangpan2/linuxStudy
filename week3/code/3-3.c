#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//测试文件描述符fd打开文件
int main(void){

	int fd;
	fd=open("./test.txt",O_RDONLY);
	printf("fd = %d \n",fd);
	return 0;



}

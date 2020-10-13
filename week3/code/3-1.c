#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//测试使用文件描述符fd打开文件
int main(void){

	int fd = open("./test.txt",O_CREAT,0644,"test");
	printf("file descriptoe =%d \n",fd);
	return 0;



}

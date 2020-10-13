#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//验证使用流来打开文件，fileno是文件描述符，使用流返回的是指针，但文件描述符是整数
int main(void){

	FILE *fp;
	fp=fopen("./test.txt","r");
	printf("fd = %d \n",fp->_fileno);
	return 0;



}

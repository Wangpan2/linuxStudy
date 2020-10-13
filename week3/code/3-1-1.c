//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
//#include <unistd.h>
//#include <stdio.h>
//为了看头文件结构，只编译，看.i文件
int main(void){

	int fd = open("./test.txt",O_CREAT,0644,"test");
	printf("file descriptoe =%d \n",fd);
	return 0;



}

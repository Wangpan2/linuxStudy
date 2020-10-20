#include "ch04.h"
char buf1[] = "abcdefghij";
char buf2[]= "ABCDEFGHIJ";
//使用append
int main()
{
	int fd;
	if((fd = open("file.hole.2",O_WRONLY|O_CREAT|O_APPEND,0644))<0)
		err_exit("create error");
	if(write(fd,buf1,10)!=10)
		err_exit("buf1 write error");
	if(lseek(fd,40,SEEK_SET)==-1)
		err_exit("lseek error");
	if(write(fd,buf2,10)!=10)
		err_exit("buf2 write error");
	exit(0);	

}

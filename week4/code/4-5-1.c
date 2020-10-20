#include "ch04.h"
//测试两个进程打开同一文件，会使用同一个系统打开文件表项，当前大写字母的进程晚一点结束，因此后面写入文件的是当前进程的随机数
int main()
{
	int n,fd;
	char buf;
	fd=open("./file.test",O_CREAT|O_RDWR,0644);
	srand(time(0));
	n=rand()%26;
	buf=(char)('A'+n);
	printf("n=%c \n",buf);
	write(fd,&buf,1);
	sleep(90);
	lseek(fd,10,SEEK_SET);
	srand(time(0));
	n=rand()%26;
	buf=(char)('A'+n);
	write(fd,&buf,1);
	sleep(80);
	close(fd);
	return 0;

}

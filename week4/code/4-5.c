#include "ch04.h"
int main()
{
	int n,fd;
	char buf;
	fd=open("./file.test",O_CREAT|O_RDWR,0644);
	srand(time(0));//随机数种子
	n=rand()%26;//0-25的随机数
	buf=(char)('a'+n);//ASCLL码值强制转换为小写字母
	printf("n=%c \n",buf);
	write(fd,&buf,1);//首位写入随机字符
	sleep(70);//休眠，为了观察
	lseek(fd,10,SEEK_SET);//指针位置为距文件开头处10
	srand(time(0));
	n=rand()%26;
	buf=(char)('a'+n);
	write(fd,&buf,1);
	sleep(50);
	close(fd);
	return 0;

}

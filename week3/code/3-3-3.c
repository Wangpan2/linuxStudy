#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//较复杂点的程序测试fdopen,与已经存在的fd联系然后使用流打开，两种打开方式不一致情况
int main(void){

	int fd;
	FILE *fp;
	fd=open("./test.txt",O_RDWR);//读写
	//fd=open("./test.txt",O_WRONLY);
	printf("fd = %d \n",fd);
	fp=fdopen(fd,"w+");//追加方式
	fprintf(fp,"test data %s \n","hello");
	fclose(fp);
	close(fd);
	return 0;



}

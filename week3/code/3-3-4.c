#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//测试freopen函数，先关闭文件再重新打开文件。
//先写入文件再读到屏幕
int main(void){

	FILE *fp;
	char buf[80];
	printf("open and create test_file. \n");
	if((fp=fopen("test_file","w"))==NULL)//检查是否打开
	{
		perror("fopen failed! \n");
		exit(1);
	}
	printf("writing string to testfile.\n");
	fputs("test date",fp);
	if((fp=freopen("test_file","r",fp))==NULL)
		perror("freopen failed!\n");
	//fp=fdopen(fd,"w+");
	printf("read string from test_file:\t");
	fgets(buf,sizeof(buf),fp);
	printf("the string is %s \n",buf);

	//fprintf(fp,"test data %s\n","hello");
	fclose(fp);
	//close(fd);
	return 0;

}

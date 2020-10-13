#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//测试fwrite函数与fgets函数，正常输入输出功能
int main(void){

	FILE *fp = fopen("./ftest.txt","w");
	char buf[80];
	memset(buf,0,sizeof(buf));
	fgets(buf,sizeof(buf),stdin);
	printf("\nthe string is %s \n",buf);
	fwrite(buf,sizeof(buf),1,fp);
	//printf("file descriptoe =%d \n",fd);
	fclose(fp);
	return 0;



}

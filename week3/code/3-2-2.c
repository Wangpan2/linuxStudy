#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//测试fwrite函数的参数，一次写完
int main(void){

	FILE *fp = fopen("./ftest.txt","w");
	char buf[80];
	int ret=0;
	memset(buf,0,sizeof(buf));
	fgets(buf,sizeof(buf),stdin);
	//printf("\nthe string is %s \n",buf);
	ret=fwrite(buf,sizeof(buf),1,fp);
	printf("number of item write to file =%d \n",ret);
	fclose(fp);
	return 0;



}

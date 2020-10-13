#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//简单测试fdopen,与3-3.c中的已经存在的fd联系
int main(void){

	FILE *fp=fdopen(1,"w+");
	//fp=fopen("./test.txt","r");
	fprintf(fp,"%s\n","hello");
	fclose(fp);



}

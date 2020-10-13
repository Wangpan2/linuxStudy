#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void){

	FILE *fp = fopen("./ftest.txt","w");
	//printf("file descriptoe =%d \n",fd);
	fclose(fp);
	return 0;



}

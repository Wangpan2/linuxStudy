#include "ch06.h"
//main的参数验证，并且准换为整数进行相加
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"参数错误！\n");
	}
	for(int i=0;i<argc;i++)
	{
		printf("argv[%d]  :%s\n",i,argv[i]);

	}
	
	int a,b,sum;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	sum=a+b;
	printf("%d + %d = %d\n",a,b,sum);
	return 0;
}


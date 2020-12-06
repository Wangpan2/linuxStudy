#include "ch09.h"
//测试exit与_exit的区别
	void foo()
	{
		fprintf(stderr,"foo says bye.\n");
	}

	void bar()
	{
		fprintf(stderr,"bar says bye.\n");
	}

	int main(int argc,char**argv)
	{
		atexit(foo);
		atexit(bar);

		fprintf(stdout,"Oops ~~~ forget a newline!\n");

		sleep(2);
		if(argc>1 && strcmp(argv[1],"exit")==0)
		{
			exit(0);
		}
		if(argc>1 && strcmp(argv[1],"_exit")==0)
		{
			_exit(0);
		}

		return 0;
	}

#include "ch07.h"
int main()
{
	int i,*pt=NULL;
	for(i=1;i<1024*1024;i++)
	{
		pt=(int *)malloc(i*1024*sizeof(int));
		if(pt!=NULL)
		{
			printf("allocate %dKB\n",4*i);

		}
		else
		{
			perror("allocate finished!\n");
			exit(1);		
		}
	}

}

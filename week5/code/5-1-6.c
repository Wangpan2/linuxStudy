#include "ch05.h"
#include "y_or_n_ques.c"

int main()
{
	int answer;
	printf("test the buffer");
	
	fprintf(stderr,"error message _IONBF test\n");
	answer = y_or_n_ques("hello,are you a student?");
	
	if(answer == 1)
	{
		printf("wish you good cores");
	}
	else
	{
		printf("wish you good salary");		
	}


	fprintf(stderr,"error message :bye\n");

}

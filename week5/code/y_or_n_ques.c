#include <stdio.h>
#include <ctype.h>
int y_or_n_ques(const char *question)
{
	fputs(question,stdout);
	while(1)
	{
		int c,answer;
		fputc(' ',stdout);
		c=tolower(fgetc(stdin));
		answer = c;
		//将这一行的其他输入给忽略
		while(c!='\n'&&c!=EOF)
		{
			c=fgetc(stdin);		
		}
		if(answer == 'y')
			return 1;
		if(answer == 'n')
			return 0;
		fputs("please answer y or n:",stdout);
	}


}

//服务器进程--主进程只监听，来一个请求则派生一个子进程去解决
#include "ch12.h"

void signal_wait(int isig)
{
	wait(NULL);
	printf("child is cleaned\n");
}

int main()
{
	int server_fifo_fd,client_fifo_fd;
	struct data_to_pass my_data;
	int nbytes;
	char client_fifo_name[256],*tmp_char_ptr;
	mkfifo(SERVER_FIFO_NAME,0777);
	server_fifo_fd = open(SERVER_FIFO_NAME,O_RDONLY);
	if(server_fifo_fd==-1)
	{
		perror("Server fifo failed!\n");
	}
	do
	{
		nbytes=read(server_fifo_fd,&my_data,sizeof(my_data));
		if(nbytes>0)
		{
			pid_t pid = fork();
			if(pid<0)
			{
				perror("fork failed!\n");
			}
			else if(pid==0)
			{
				tmp_char_ptr=my_data.data;
			
				while(*tmp_char_ptr)
				{
					if(isupper(*tmp_char_ptr))
					{
						*tmp_char_ptr=tolower(*tmp_char_ptr);
					}
					else if(islower(*tmp_char_ptr))
					{
						*tmp_char_ptr=toupper(*tmp_char_ptr);
					}
					else if(*tmp_char_ptr=='\n')
					{
						*tmp_char_ptr='\0';
					}
					tmp_char_ptr++;
				}
				sprintf(client_fifo_name,CLIENT_FIFO_NAME,my_data.client_pid);
				client_fifo_fd = open(client_fifo_name,O_WRONLY);
				if(client_fifo_fd!=-1)
				{
					write(client_fifo_fd,&my_data,sizeof(my_data));//把倒转后的回复发给客户
					close(client_fifo_fd);
				}
				exit(0);
			}
			else
			{
				if(signal(SIGCHLD,signal_wait)==SIG_ERR)
				{
					perror("install signal_wait!");
				}
			
			}
			
		}
	}while(1);
	close(server_fifo_fd);
	unlink(SERVER_FIFO_NAME);
	return 0;
}
	
	

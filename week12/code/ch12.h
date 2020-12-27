#include <stdio.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <setjmp.h>
#include <wait.h>
#include <errno.h>
#include <sys/time.h>

#define err_exit(MESSAGE)(\
	perror(MESSAGE),\
	exit(1)\
)

#define INFILE "./in.txt"
#define OUTFILE "./log.dat"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH


#define PIPE_BUF 100
#define FIFO_FILE "./testfifo"
#define TEN_MEG 1000

#define SERVER_FIFO_NAME "./serv_fifo"
#define CLIENT_FIFO_NAME "./client_%d_fifo"
#define BUFFER_SIZE 132
struct data_to_pass{
	pid_t client_pid;
	char data[BUFFER_SIZE];
};

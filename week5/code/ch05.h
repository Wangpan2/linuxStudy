#include <stdio.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#define err_exit(MESSAGE)(\
	perror(MESSAGE),\
	exit(1)\
)

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "newfile.h"

void create_newfile(char *filename){
	int fd = open(filename, O_WRONLY | O_CREAT, 0644);
	if(fd < 0){
		perror("create file");
		return;
	}

	close(fd);
}

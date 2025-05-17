#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include "newdir.h"

void create_directory(char *directory_name){
	if(mkdir(directory_name, 0777) == -1){
		perror("mkdir");
		return;
	}
}

// TODO:
// ==> Same as newfile.c

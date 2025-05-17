#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "delfile.h"

void delete_file(char *filename){
	if(unlink(filename) == -1) perror("unlink");
	return;
}

// TODO:
// ==> Delete multiple file

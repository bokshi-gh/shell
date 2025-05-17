#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "goto.h"

extern char *cwd;

void change_directory(char *path){
	if(chdir(path) == -1) perror("chdir");
	if((getcwd(cwd, PATH_MAX)) == NULL){
		perror("cwd");
		exit(1);
	}
	return;
}

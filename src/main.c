#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <pwd.h>
#include "macros.h"

char *user_name;
char *host_name;
char *cwd;

void get_user_name(){
	struct passwd *pwd;
	pwd = getpwuid(getuid());
	if(pwd == NULL){
		perror("pwd");
		exit(1);
	};

	user_name = pwd->pw_name;
}

void get_host_name(){
	if(gethostname(host_name, HOST_NAME_MAX) == -1){
		perror("hostname");
		exit(1);
	}
}

void get_cwd(){
	if((getcwd(cwd, PATH_MAX)) == NULL){
		perror("cwd");
		exit(1);
	}
}

void prompt(char *command){
	printf("%s@%s:%s≫ ", user_name, host_name, cwd);
	if((fgets(command, MAX_COMMAND_LENGTH, stdin)) == NULL){
		perror("fgets");
		exit(1);
	}
}

int main(int argc, char *argv[]){
	char command[MAX_COMMAND_LENGTH];
	get_user_name();
	if((host_name = malloc(HOST_NAME_MAX)) == NULL){ 
		perror("malloc");
		exit(1);
	}
	get_host_name();
	if((cwd = malloc(PATH_MAX)) == NULL){
		perror("malloc");
		exit(1);
	}
	get_cwd();

	while(true){
		prompt(command);
	}

	// cleanup() call clean function before program exist to avoid memory leaks
	return 0;
}

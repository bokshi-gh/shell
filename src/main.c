#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <pwd.h>
#include <string.h>
#include "macros.h"
#include "argument_handler.h"
#include "command_parser.h"
#include "command_handler.h"

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
	printf("%s@%s:%s$ ", user_name, host_name, cwd);
	if((fgets(command, MAX_COMMAND_LENGTH, stdin)) == NULL){
		perror("fgets");
		exit(1);
	}
	command[strcspn(command, "\n")] = '\0'; // Remove trailing newline or whitespace
}

int main(int argc, char *argv[]){

	if(argc != 1){
		handle_argument(argc, argv);
		exit(0);
	}

	char command[MAX_COMMAND_LENGTH];
	char *command_tokens[256];

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
		parse_command(command, command_tokens);
		handle_command(command, command_tokens);
	}

	// TODO: call cleanup() function before program exist to avoid memory leaks
	return 0;
}

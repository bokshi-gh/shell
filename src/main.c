#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include "command_handler.h"

const char *username;
char hostname[256];
char cwd[1024]; // Buffer to store the current working directory

void prompt(char *command){
	char *light_blue = "\e[1;34m";
	char *light_green = "\e[1;32m";
	char *reset = "\e[0m";

	printf("%s%s@%s%s:%s[%s%s%s]%s▶ ", light_green, username, hostname, reset, light_green, light_blue, cwd, light_green, reset);

	// Use fgets instead of scanf for safer input, including spaces
	if (fgets(command, 100, stdin) == NULL) {
		perror("fgets failed");
		exit(1);
	}

	// Remove newline character if present (fgets includes a newline)
	command[strcspn(command, "\n")] = 0;
}

void get_username(){
	username = getlogin();
	if(username == NULL){
		struct passwd *pw = getpwuid(geteuid());
		if(pw) username = pw->pw_name;
		else username = "unknown";
	}
}

void get_hostname(){
	if(gethostname(hostname, sizeof(hostname)) != 0){
		perror("gethostname failed");
		exit(1);
	}
}

void get_cwd(){
	if(getcwd(cwd, sizeof(cwd)) == NULL){
		perror("getcwd failed");
		exit(1);
	}
}

void parse_command(char *command, char *args[]){
	int index = 0;
        char *token = strtok(command, " ");
	while(token != NULL && index < 5){
		args[index++] = token;
		token = strtok(NULL, " ");
	}
	args[index] = NULL;
}

int main(){
	char *command = malloc(100 * sizeof(char));
	char *args[6];
	if(command == NULL){
		perror("malloc failed");
		return 1;
	}

	get_username();
	get_hostname();
	get_cwd();

	while(true){
		prompt(command);
		parse_command(command, args);
		handle_command(command, args);
	}

	return 0;
}

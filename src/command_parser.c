#include <string.h>
#include "command_parser.h"

void parse_command(char command[], char *command_tokens[]){
	int index = 0;
	char *token = strtok(command, " ");

	while(token != NULL){
		command_tokens[index++] = token;
		token = strtok(NULL, " ");
	}
	command_tokens[index] = NULL;
}

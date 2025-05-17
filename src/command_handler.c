#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_handler.h"
#include "macros.h"
#include "list.h"
#include "newfile.h"
#include "newdir.h"
#include "delfile.h"

void handle_command(char command[], char *command_tokens[]) {
	if ((strcmp(command_tokens[0], "clean") == 0) && command_tokens[1] == NULL) {
		CLEAR_TERMINAL();
		return;
	}
	else if ((strcmp(command_tokens[0], "esc") == 0) && command_tokens[1] == NULL) {
		// TODO: Add cleanup() if needed before exiting
		exit(0);
	}
	else if (strcmp(command_tokens[0], "list") == 0){
		list_directory();
	}
	else if (strcmp(command_tokens[0], "newfile") == 0){
		if(command_tokens[1] == NULL){
			// TODO: Implement invalid arg error
			return;
		}
		create_file(command_tokens[1]);
	}
	else if (strcmp(command_tokens[0], "newdir") == 0){
		if(command_tokens[1] == NULL){
			// TODO: Implement invalid arg error
			return;
		}
		create_directory(command_tokens[1]);
	}
	else if (strcmp(command_tokens[0], "delfile") == 0){
		if(command_tokens[1] == NULL){
			// TODO: Implement invalid arg error
			return;
		}
		delete_file(command_tokens[1]);
	}
	// Fallback to executing system command if not handled internally
	else {
		int ret = system(command);

		if (ret != 0) {
			// Remove system-generated error message from the terminal
			printf("\033[1A\033[2K");

			// Display custom error message
			printf("rumi: command \"%s\" not found\n", command_tokens[0]);
			printf("try: rumi -g or rumi --guide\n");
		}
	}
}

// NOTE: Arguments and flags are not considered or filtered for some command
// TODO: Need to implement parsing and filtering on next version

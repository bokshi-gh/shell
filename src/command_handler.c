#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_handler.h"
#include "macros.h"

void handle_command(char command[], char *command_tokens[]) {
	if ((strcmp(command_tokens[0], "clean") == 0) && command_tokens[1] == NULL) {
		CLEAR_TERMINAL();
		return;
	}
	else if ((strcmp(command_tokens[0], "escape") == 0) && command_tokens[1] == NULL) {
		// TODO: Add cleanup() if needed before exiting
		exit(0);
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


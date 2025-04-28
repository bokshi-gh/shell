#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "command_handler.h"
#include "list.h"
#include "newfile.h"

void handle_command(char *command, char *args[]){
	if(strcmp(args[0], "escape") == 0){
		free(command);
		command = NULL;
		exit(0);
	}else if(strcmp(args[0], "clean") == 0){
		printf("\e[H\e[J");
	}else if(strcmp(args[0], "list") == 0){
		list_cwd();
	}else if(strcmp(args[0], "newfile") == 0){
		if(args[1] == NULL){
			printf("Err: Filename is missing!\nUsage: newfile <file_name>\n");
			return;
		}
		create_newfile(args[1]);
	}	
	else{
		printf("Err: command %s not found!\nHelp: try phi -h or phi --help\n", command);
	}
}

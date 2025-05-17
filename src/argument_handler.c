#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "argument_handler.h"
#include "macros.h"

void handle_argument(int argc, char *argv[]){
	if(argc != 1){
		if(argc == 2){
			if((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)){
				printf("rumi %s\n", VERSION);
				exit(0);
			}else if((strcmp(argv[1], "-g") == 0) || (strcmp(argv[1], "--guide") == 0)){
			}else{
				printf("rumi: Invalid argument \"%s\"\n", argv[1]);
				printf("try: rumi -g or rumi --guide\n");
				exit(1);
			}

			exit(0);
		}else{
			printf("rumi: Invalid arguments\n");
			printf("Try: rumi -h or rumi --help\n");
			exit(1);
		}


		return;
	}
}

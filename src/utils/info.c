#include <stdio.h>

#include "info.h"
#include "macros.h"

void display_info(){
	printf("Shell Info\n");
	
	printf("\n");
	
	printf("Version: %s\n", VERSION);
	printf("Description: %s\n", DESC);
	printf("Author: %s\n", AUTHOR);
	printf("License: %s\n", LICENSE);
	printf("GitHub: %s\n", GITHUB);
}

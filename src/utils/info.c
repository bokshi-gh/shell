#include <stdio.h>
#include "info.h"
#include "macros.h"

void display_info(){
	printf("\n");
	printf(
		"\t██████╗ ██╗   ██╗███╗   ███╗██╗\n"
		"\t██╔══██╗██║   ██║████╗ ████║██║\n"
		"\t██████╔╝██║   ██║██╔████╔██║██║\n"
		"\t██╔══██╗██║   ██║██║╚██╔╝██║██║\n"
		"\t██║  ██║╚██████╔╝██║ ╚═╝ ██║██║\n"
		"\t╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝╚═╝\n"
	);

	printf("\n");

	printf("\033[32m=============== Rumi Shell Info ===============\033[0m\n");
	
	printf("\n");
	
	printf("Version: %s\n", VERSION);
	printf("Author: %s\n", AUTHOR);
	printf("GitHub: %s\n", GITHUB);
	printf("Description: %s\n", DESC);
	printf("License: %s\n", LICENSE);
}

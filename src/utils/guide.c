#include <stdio.h>
#include "guide.h"

void display_guide(){
	printf("\n\033[32m==================== Rumi Guide ====================\033[0m\n");

	printf("\n");

	printf("Rumi CLI Commands:\n");
	printf("  rumi -i, --info      Show information of rumi\n");
	printf("  rumi -v, --version   Show version information\n");
	printf("  rumi -g, --guide     Show this guide\n");
	
	printf("\n");

	printf("Rumi Shell Commands:\n");
	printf("  clean                Clear the terminal screen\n");
	printf("  escape               Exit the shell\n");
	printf("  <non_rumi_command>   Executed as a system command (e.g., ls, gcc, vim)\n");

	printf("\n");
}

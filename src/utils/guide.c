#include <stdio.h>
#include "guide.h"

void display_guide(){
	printf("\033[32m==================== Shell Guide ====================\033[0m\n");

	printf("\n");

	printf("Shell CLI Commands:\n");
	printf("  shell -i, --info      Show information of rumi\n");
	printf("  shell -v, --version   Show version information\n");
	printf("  shell -g, --guide     Show this guide\n");

	printf("\n");

	printf("Shell Commands:\n");
	printf("  clean              - Clear the terminal screen\n");
	printf("  esc                - Exit the shell\n");
	printf("  list               - List files and directories in the current directory\n");
	printf("  newfile <filename> - Create an empty file with the given name\n");
	printf("  delfile <filename> - Delete the specified file\n");
	printf("  newdir <dirname>   - Create a new directory with the given name\n");
	printf("  deldir <dirname>   - Delete directory with the given name\n");
	printf("  print <text>       - Print the specified text to the terminal\n");
	printf("  read <filename>    - Display the contents of the specified file\n");
	printf("  goto <pathname>    - Change the current directory to the specified path\n");
}

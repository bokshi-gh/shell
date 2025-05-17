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
	printf("  clean              - Clear the terminal screen\n");
	printf("  esc                - Exit the shell\n");
	printf("  list               - List files and directories in the current directory\n");
	printf("  newfile <filename> - Create an empty file with the given name\n");
	printf("  delfile <filename> - Delete the specified file\n");
	printf("  newdir  <dirname>  - Create a new directory with the given name\n");
	printf("  deldir  <dirname>  - Delete an empty directory with the given name\n");
	printf("  print \"<text>\"   - Print the specified text to the terminal\n");
	printf("  read <filename>    - Display the contents of the specified file\n");
	printf("  goto <pathname>    - Change the current directory to the specified path\n);
	printf("  <non_rumi_command> - Executed as a system command (e.g., ls, gcc, vim)\n");

	printf("\n");
}

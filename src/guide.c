#include <stdio.h>
#include "guide.h"

void display_guide() {
    printf("Shell Guide\n\n");

    printf("Shell CLI Commands:\n");
    printf("  shell -g, --guide     Show this guide\n");
    printf("  shell -v, --version   Show version information\n");
    printf("  shell -i, --info      Show information about shell\n\n");

    printf("Shell Commands:\n");
    printf("  list               - List files and directories in the current directory\n");
    printf("  goto <pathname>    - Change the current directory\n");
    printf("  read <filename>    - Display the contents of a file\n");
    printf("  print <text>       - Print text to the terminal\n");
    printf("  newfile <filename> - Create an empty file\n");
    printf("  delfile <filename> - Delete a file\n");
    printf("  newdir <dirname>   - Create a new directory\n");
    printf("  deldir <dirname>   - Delete a directory\n");
    printf("  clean              - Clear the terminal screen\n");
    printf("  esc                - Exit the shell\n");
}

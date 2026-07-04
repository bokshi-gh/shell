#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "macros.h"

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

void display_info(){
	printf("Shell Info\n");
	
	printf("\n");
	
	printf("Version: %s\n", VERSION);
	printf("Description: %s\n", DESC);
	printf("Author: %s\n", AUTHOR);
	printf("GitHub: %s\n", GITHUB);
}

char* format_cwd(char *cwd) {
    char *home = getenv("HOME");

    if (home == NULL || cwd == NULL) {
        return cwd;
    }

    size_t home_len = strlen(home);

    if (strncmp(cwd, home, home_len) == 0) {

        // "~" + remaining path + null terminator
        size_t new_len = strlen(cwd + home_len) + 2;

        char *result = malloc(new_len);
        if (result == NULL) {
            return cwd; // fallback
        }

        snprintf(result, new_len, "~%s", cwd + home_len);

        return result;
    }

    return cwd;
}

char* expand_path(const char *path) {
    if (path[0] != '~') {
        return strdup(path);  // no expansion needed
    }

    char *home = getenv("HOME");

    char *result = malloc(strlen(home) + strlen(path));
    sprintf(result, "%s%s", home, path + 1);

    return result;
}

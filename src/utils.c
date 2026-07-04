#include <limits.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "macros.h"

char *user_name = NULL;

void init_user_name(void) {
    struct passwd *pwd = getpwuid(getuid());

    if (!pwd) {
        perror("getpwuid");
        exit(EXIT_FAILURE);
    }

    user_name = pwd->pw_name;
}

void init_host_name(char *host_name) {
    if (gethostname(host_name, HOST_NAME_MAX) == -1) {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }
}

char* get_cwd(void) {
    char *cwd = getcwd(NULL, 0);

    if (!cwd) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    return cwd;
}

char* format_cwd(char *cwd) {
    char *home = getenv("HOME");

    if (!home || !cwd) {
        return cwd;
    }

    size_t home_len = strlen(home);

    if (strncmp(cwd, home, home_len) == 0) {

        size_t new_len = strlen(cwd + home_len) + 2;

        char *result = malloc(new_len);

        if (!result) return cwd;

        snprintf(result, new_len, "~%s", cwd + home_len);

        return result;
    }

    return cwd;
}

char* expand_path(const char *path) {
    if (!path) return NULL;

    if (path[0] != '~') {
        return strdup(path);
    }

    char *home = getenv("HOME");

    if (!home) return strdup(path);

    size_t len = strlen(home) + strlen(path) + 1;

    char *result = malloc(len);

    if (!result) return NULL;

    snprintf(result, len, "%s%s", home, path + 1);

    return result;
}

void display_guide() {
    printf("Shell Guide\n\n");

    printf("Command-line Options:\n");
    printf("  shell -g, --guide     Show this guide\n");
    printf("  shell -v, --version   Show version information\n");
    printf("  shell -i, --info      Show information about this shell\n\n");

    printf("Built-in Commands:\n");
    printf("  list               List files and directories\n");
    printf("  goto <path>        Change the current directory\n");
    printf("  read <file>        Display a file's contents\n");
    printf("  print <text>       Display text\n");
    printf("  newfile <file>     Create an empty file\n");
    printf("  delfile <file>     Delete a file\n");
    printf("  newdir <dir>       Create a directory\n");
    printf("  deldir <dir>       Delete a directory\n");
    printf("  clean              Clear the screen\n");
    printf("  esc                Exit the shell\n");
}

void display_info(){
	printf("Shell Info\n\n");
	
	printf("Version: %s\n", VERSION);
	printf("Description: %s\n", DESC);
	printf("Author: %s\n", AUTHOR);
	printf("GitHub: %s\n", GITHUB);
}

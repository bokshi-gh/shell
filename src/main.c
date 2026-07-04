#include <errno.h>
#include <limits.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "argument_handler.h"
#include "command_handler.h"
#include "command_parser.h"
#include "macros.h"

char *user_name;
char *host_name;
char *cwd;

void get_user_name(void) {
    struct passwd *pwd = getpwuid(getuid());

    if (pwd == NULL) {
        perror("getpwuid");
        exit(EXIT_FAILURE);
    }

    user_name = pwd->pw_name;
}

void get_host_name(void) {
    if (gethostname(host_name, HOST_NAME_MAX) == -1) {
        perror("gethostname");
        exit(EXIT_FAILURE);
    }
}

void get_cwd(void) {
    if (getcwd(cwd, PATH_MAX) == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }
}

void prompt(char *command) {
    get_cwd();
    
    printf(
        "%s%s@%s%s:%s%s%s$ ",
        GREEN, user_name, host_name, RESET,
        BLUE, cwd, RESET
    );

    if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    command[strcspn(command, "\n")] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 1) {
        handle_argument(argc, argv);
        return 0;
    }

    get_user_name();

    host_name = malloc(HOST_NAME_MAX);
    cwd = malloc(PATH_MAX);

    if (host_name == NULL || cwd == NULL) {
        perror("malloc");
        free(host_name);
        free(cwd);
        return EXIT_FAILURE;
    }

    get_host_name();

    char command[MAX_COMMAND_LENGTH];
    while (true) {
        prompt(command);
        parse_command(command);
        handle_command(command);
    }

    free(host_name);
    free(cwd);

    return EXIT_SUCCESS;
}

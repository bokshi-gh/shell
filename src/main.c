#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"
#include "argument_handler.h"
#include "command_parser.h"
#include "command_handler.h"
#include "macros.h"

char *host_name;
char *cwd;

void prompt(char *command) {
    char *raw_cwd = get_cwd();
    char *display_path = format_cwd(raw_cwd);

    printf(
        "%s%s@%s%s:%s%s%s$ ",
        GREEN, user_name, host_name, RESET,
        BLUE, display_path, RESET
    );

    if (display_path != raw_cwd) {
        free(display_path);
    }

    free(raw_cwd);

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

    init_user_name();

    host_name = malloc(HOST_NAME_MAX);
    if (!host_name) return EXIT_FAILURE;

    init_host_name(host_name);

    char command[MAX_COMMAND_LENGTH];
    char *command_tokens[256];

    while (true) {
        prompt(command);
        parse_command(command, command_tokens);
        handle_command(command, command_tokens);
    }

    free(host_name);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "argument_handler.h"
#include "command_handler.h"
#include "macros.h"
#include "list.h"
#include "newfile.h"
#include "newdir.h"
#include "delfile.h"
#include "read.h"
#include "goto.h"
#include "deldir.h"

void handle_command(char command[], char *command_tokens[]) {
    (void)command;

    if ((strcmp(command_tokens[0], "clean") == 0) && command_tokens[1] == NULL) {
        CLEAR_TERMINAL();
        return;
    }

    if ((strcmp(command_tokens[0], "esc") == 0) && command_tokens[1] == NULL) {
        exit(0);
    }

    if (strcmp(command_tokens[0], "goto") == 0) {
        if (command_tokens[1] == NULL) {
            printf("goto: missing pathname\n");
            return;
        }
        
        change_directory(command_tokens[1]);
        return;
    }

    if (strcmp(command_tokens[0], "list") == 0) {
        list_directory();
        return;
    }

    if (strcmp(command_tokens[0], "read") == 0) {
        if (command_tokens[1] == NULL) {
            printf("read: missing filename\n");
            return;
        }

        read_file(command_tokens[1]);
        return;
    }

    if (strcmp(command_tokens[0], "newfile") == 0) {
        if (command_tokens[1] == NULL) {
            printf("newfile: missing filename\n");
            return;
        }

        create_file(command_tokens[1]);
        return;
    }

    if (strcmp(command_tokens[0], "newdir") == 0) {
        if (command_tokens[1] == NULL) {
            printf("newdir: missing directory name\n");
            return;
        }

        create_directory(command_tokens[1]);
        return;
    }

    if (strcmp(command_tokens[0], "delfile") == 0) {
        if (command_tokens[1] == NULL) {
            printf("delfile: missing filename\n");
            return;
        }

        delete_file(command_tokens[1]);
        return;
    }

    if (strcmp(command_tokens[0], "deldir") == 0) {
        if (command_tokens[1] == NULL) {
            printf("deldir: missing directory name\n");
            return;
        }

        delete_directory(command_tokens[1]);
        return;
    }

    if (strcmp(command_tokens[0], "print") == 0) {
        if (command_tokens[1] == NULL) {
            printf("print: missing text\n");
            return;
        }
    
        for (int i = 1; command_tokens[i] != NULL; i++) {
            printf("%s", command_tokens[i]);
    
            if (command_tokens[i + 1] != NULL) {
                printf(" ");
            }
        }

        printf("\n");
        return;
    }
    
    printf("shell: command not found: %s\n", command_tokens[0]);
}

/*
 * NOTE:
 * Command arguments are minimally validated.
 * Extra arguments and command flags are currently ignored.
 *
 * TODO:
 * - Validate the exact number of arguments for each command.
 * - Add support for command-specific flags/options.
 * - Improve command parsing (quoted strings, escaping, etc.).
 */

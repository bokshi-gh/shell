#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "argument_handler.h"
#include "macros.h"
#include "info.h"
#include "guide.h"

void handle_argument(int argc, char *argv[]) {
    if (argc == 2) {
        if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
            printf("shell %s\n", VERSION);
        } else if ((strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "--info") == 0)) {
            display_info();
        } else if ((strcmp(argv[1], "-g") == 0) || (strcmp(argv[1], "--guide") == 0)) {
            display_guide();
        } else {
            printf("rumi: Invalid argument \"%s\"\n", argv[1]);
            printf("Try: rumi -g or rumi --guide\n");
        }

        return;
    }

    printf("shell: Invalid arguments\n");
    printf("Try: shell -g or shell --guide\n");
}

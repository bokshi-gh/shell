#include <stdio.h>
#include <unistd.h>

#include "goto.h"

void change_directory(char *path) {
    if (chdir(path) == -1) {
        perror("chdir");
    }
}

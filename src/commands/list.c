#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "macros.h"
#include "list.h"

void list_directory(char *path) {
    DIR *d = opendir(path);

    if (d == NULL) {
        perror("opendir failed");
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(d)) != NULL) {
        if ((strcmp(entry->d_name, ".") == 0) ||
            (strcmp(entry->d_name, "..") == 0)) {
            continue;
        }

        if (entry->d_type == DT_DIR) {
            printf("%s%s/%s  ", BLUE, entry->d_name, RESET);
        } else {
            printf("%s  ", entry->d_name);
        }
    }

    printf("\n");
    closedir(d);
}

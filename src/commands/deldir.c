#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#include "deldir.h"

void delete_directory(char *directory_name) {
    DIR *d = opendir(directory_name);

    if (d == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *p;

    while ((p = readdir(d)) != NULL) {
        if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")) {
            continue;
        }

        size_t len = strlen(directory_name) + strlen(p->d_name) + 2;
        char *buff = malloc(len);

        if (!buff) {
            perror("malloc");
            continue;
        }

        snprintf(buff, len, "%s/%s", directory_name, p->d_name);

        if (p->d_type == DT_DIR) {
            delete_directory(buff);
        } else {
            unlink(buff);
        }

        free(buff);
    }

    closedir(d);

    if (rmdir(directory_name) != 0) {
        perror("rmdir");
    }
}

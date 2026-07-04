#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* expand_path(const char *path) {
    if (path[0] != '~') {
        return strdup(path);  // no expansion needed
    }

    char *home = getenv("HOME");

    char *result = malloc(strlen(home) + strlen(path));
    sprintf(result, "%s%s", home, path + 1);

    return result;
}

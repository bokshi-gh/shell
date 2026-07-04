#include <stdio.h>
#include <errno.h>

#include "newfile.h"

void create_file(char *filename) {
    FILE *fp = fopen(filename, "wx");
    
    if (fp == NULL) {
        perror("open");
        return;
    }
    
    fclose(fp);
}

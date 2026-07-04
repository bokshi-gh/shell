#include <stdio.h>
#include <errno.h>

#include "newfile.h"

void create_file(char *filename) {
    FILE *fp = fopen(filename, "wx");
    
    if (fp == NULL) {
        // If the error is strictly because the file already exists, do nothing silently
        if (errno == EEXIST) {
            return; 
        }
        
        // Print any other error (e.g., "Permission denied", "No such file or directory")
        perror("open");
        return;
    }
    
    fclose(fp);
}

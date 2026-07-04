#include <stdio.h>
#include "newfile.h"

void create_file(char *filename){
	FILE *fp = fopen(filename, "w");
	fclose(fp);
}

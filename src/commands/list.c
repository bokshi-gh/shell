#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "list.h"

void list_cwd(){
	DIR *dir = opendir(".");
	if (dir == NULL) {
		perror("ls");
		exit(1);
	}

	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.')
			printf("%s  ", entry->d_name);
	}

	printf("\n");
	closedir(dir);
}

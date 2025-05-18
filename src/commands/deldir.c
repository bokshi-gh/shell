#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "deldir.h"

void delete_directory(char *directory_name){
	DIR* d = opendir(directory_name);
	struct dirent *p;

	while((p = readdir(d)) != NULL){
		char *buff;
		size_t len;

		if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, "..")) {
			continue;
		}

		len = strlen(directory_name) + strlen(p->d_name)+2;
		buff = malloc(len);

		if (!buff) {
			perror("malloc");
			break;
		}

		snprintf(buff, len, "%s/%s", directory_name, p->d_name);

		if(p->d_type == DT_DIR){
			delete_directory(buff);
		}else{
			unlink(buff);
		}

		free(buff);
		buff = NULL;
	}

	closedir(d);

	if (rmdir(directory_name) != 0) {
		perror("rmdir");
	}

}

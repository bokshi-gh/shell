#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "list.h"

void list_directory(){
	DIR *d = opendir(".");
	struct dirent* entry;

	while((entry = readdir(d)) != NULL){
		if((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) continue;
		
		if(entry->d_type == DT_REG) printf("%s ", entry->d_name);
		else printf("%s/ ", entry->d_name);

	}

	printf("\n");
	closedir(d);
}

// TODO:
// ==> Display or hide hidden file/folder specified by the flag
// ==> Display directory contents of given path

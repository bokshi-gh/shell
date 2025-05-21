#include <stdio.h>
#include <errno.h>
#include "read.h"

void read_file(char *filename){
	FILE* fp = fopen(filename, "r");
	if(fp == NULL){
		perror("fopen");
		return;
	}

	char ch;

	while((ch = fgetc(fp)) != EOF){
		printf("%c", ch);
	}

	printf("\n");

}

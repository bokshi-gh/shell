#pragma once

#include <stdbool.h>

void display_guide();
void display_info();

void init_user_name(void);
void init_host_name(char *host_name);
char* get_cwd(void);

char* format_cwd(char *cwd);
char* expand_path(const char *path);

extern char *user_name;

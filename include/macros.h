#pragma once

#define VERSION "v1.0.0"
#define AUTHOR "devRajeshThapa"
#define GITHUB "https://github.com/devrajeshthapa/shell.git"
#define DESC "A minimal shell written in C/C++"
#define LICENSE "GNU General Public License v3.0"

#define MAX_COMMAND_LENGTH 4096
#define CLEAR_TERMINAL() printf("\033[2J\033[H")

//ANSI escape sequence
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"


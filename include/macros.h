#pragma once

#define VERSION "v1.0.0"
#define AUTHOR "Rajesh Thapa (bokshi)"
#define GITHUB "https://github.com/bokshi-gh/shell.git"
#define DESC "A tiny shell written in C."
#define LICENSE "GNU General Public License v3.0"

#define CLEAR_TERMINAL() printf("\033[2J\033[H")

// ANSI Escape Sequence
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

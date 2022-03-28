#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define CWB    "\x1b[7m"
#define CR   "\x1b[0m"

int main() {
    printf(ANSI_COLOR_RED     "This text is RED!"     CR "\n");
    printf(ANSI_COLOR_GREEN   "This text is GREEN!"   CR "\n");
    printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  CR "\n");
    printf(ANSI_COLOR_BLUE    "This text is BLUE!"    CR "\n");
    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" CR "\n");
    printf(ANSI_COLOR_CYAN    "This text is CYAN!"    CR "\n");
    printf(CWB    "        "    CR "   " CWB "      " CR);
    getchar();
}
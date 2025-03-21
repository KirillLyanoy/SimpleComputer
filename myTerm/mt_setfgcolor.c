#include "myTerm.h"

int mt_setfgcolor(enum color color) {
    if (color < BLACK || color > DEFAULT) return -1;
    printf("\033[3%dm", color);
    return 0;
}
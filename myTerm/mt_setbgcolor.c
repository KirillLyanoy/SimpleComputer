#include "myTerm.h"

int mt_setbgcolor(enum color color) {
    if (color < BLACK || color > DEFAULT) return -1;
    printf("\033[4%dm", color);
    return 0;
}
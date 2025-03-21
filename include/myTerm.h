#ifndef __GUARD_MYTERM_H
#define __GUARD_MYTERM_H

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

enum color {
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7,
    DEFAULT = 9
};

int mt_clrscr(void);

int mt_gotoXY(int x, int y);

int mt_getscreensize(int* rows, int* cols);

int mt_setfgcolor(enum color color);

int mt_setbgcolor(enum color color);

#endif /* __GUARD_MYTERM_H */
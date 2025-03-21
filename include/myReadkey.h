#ifndef __GUARD_MYREADKEY_H
#define __GUARD_MYREADKEY_H

#include <unistd.h>
#include <termios.h>

enum keys {
    KEY_I = 9, KEY_L = 12, KEY_R = 18, KEY_S = 19, KEY_T = 20,

    KEY_1 = 27, KEY_2 = 28, KEY_3 = 29, KEY_4 = 30, KEY_5 = 31, KEY_6 = 32, KEY_7 = 33, KEY_8 = 34, KEY_9 = 35, KEY_0 = 36,

    KEY_UP = 37, KEY_DOWN = 38, KEY_LEFT = 39, KEY_RIGHT = 40, 

    KEY_F5 = 41, KEY_F6 = 42,    
};

static struct termios original_term;

int rk_readkey (enum keys *key);

int rk_mytermsave(void);

int rk_mytermrestore(void);

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int
sigint);

#endif /* __GUARD_MYREADKEY_H */
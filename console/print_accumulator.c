#include "console.h"

int print_accumulator(int accumulator) {    
    mt_gotoXY (75, 2); printf("+%04X", accumulator);
    mt_gotoXY (0, 23);
    return 0;
}
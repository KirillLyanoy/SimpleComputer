#include "console.h"

int set_accumulator(int *accumulator) {
    int acc;
    
    rk_mytermrestore();
    printf("Accumulator value: ");
    scanf("%d", &acc);
    rk_mytermregime(0, 0, 1, 0, 1);
    if (acc < 0 || acc > 65535) return -1;

    *accumulator = acc;
    return 0; 
}
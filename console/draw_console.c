#include "console.h"

int draw_console(int *rows, int *cols) {    
    mt_getscreensize(rows, cols);
    bc_box(1, 1, 12, 61);
    bc_box(1, 63, 3, 30);
    bc_box(4, 63, 3, 30);
    bc_box(7, 63, 3, 30);
    bc_box(10, 63, 3, 30);
    bc_box(13, 1, 10, 42);
    bc_box(13, 44, 10, 49);
    bc_box(23, 1, 7, 92);
    mt_gotoXY (29, 1); printf("Memory");
    mt_gotoXY (72, 1); printf("accumulator");
    mt_gotoXY (70, 4); printf("instructionCounter");
    mt_gotoXY (73, 7); printf("Operation");
    mt_gotoXY (75, 10); printf("Flags");
    mt_gotoXY (50, 13); printf("Keys:");
    mt_gotoXY (46, 14); printf(" l - load");
    mt_gotoXY (46, 15); printf(" s - save");
    mt_gotoXY (46, 16); printf(" r - run");
    mt_gotoXY (46, 17); printf(" t - step");
    mt_gotoXY (46, 18); printf(" i - reset");
    mt_gotoXY (46, 19); printf(" F5 - accumulator");
    mt_gotoXY (46, 20); printf(" F6 - instructionCounter");
    mt_gotoXY (43, 23); printf("CPU cache");    
    mt_gotoXY (2, 24); printf("%d:", CPU_cache_lines[0]);
    mt_gotoXY (2, 25); printf("%d:", CPU_cache_lines[1]);
    mt_gotoXY (2, 26); printf("%d:", CPU_cache_lines[2]);
    mt_gotoXY (2, 27); printf("%d:", CPU_cache_lines[3]);
    mt_gotoXY (2, 28); printf("%d:", CPU_cache_lines[4]);
    mt_gotoXY (0, 30);
    return 0;
}
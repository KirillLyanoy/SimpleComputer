#include "console.h"

int print_memory(int sc_memory[], int selected_cell_index) {
    if (sc_memory == NULL) return -1;
    int x = 2, y = 2;
    int command, operand, value, selected_cell_value;
    for (int i = 0; i < 100; i+=10) {
        mt_gotoXY(x, y);
        for (int j = 0; j < 10; j++) {
            sc_memoryGet(i + j, &value);
            if (selected_cell_index == i + j) {
                mt_setfgcolor(BLACK);
                mt_setbgcolor(WHITE);
                printf("+%04d", sc_commandDecode(value, &command, &operand));
                selected_cell_value = value;
                mt_setbgcolor(DEFAULT);
                mt_setfgcolor(DEFAULT);
                printf(" ");
            }
            else printf("+%04d ", sc_commandDecode(value, &command, &operand));
        }
        printf("\n");
        y +=1; 
        x = 2;  
    }
    print_big_chars(selected_cell_value);
       
    mt_gotoXY (0, 24);
    return 0;
}
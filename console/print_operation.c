#include "console.h"

int print_operation() {

    int value;
    sc_memoryGet(selected_cell_index, & value);

    if (((value >> 14) & 1) == 1) {
            int command;
            int operand;

            sc_commandDecode(value, &command, &operand);

            mt_gotoXY (79, 5); printf("+%d : %d", command, operand);
            mt_gotoXY (0, 23);
    }
    return 0;
}
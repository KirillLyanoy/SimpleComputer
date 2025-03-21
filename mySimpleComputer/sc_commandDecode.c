#include "mySimpleComputer.h"

int sc_commandDecode(int value, int* command, int* operand) {
    if (value < 0 || value > 16383) {
        registr = registr | (1 << (COMMAND_NOT_FOUND - 1));
        return -1;
    }
    else {
        *command = (value >> 7) & 0x7F;
        *operand = value & 0x7F;
        return 0;
    }
}
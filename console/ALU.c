#include "console.h"

int ALU(int command, int operand) {

    switch(command) {
        case 30: 
            if (operand > 0 && operand < MEMORY_SIZE) {
                int memory_value;
                sc_memoryGet(operand, &memory_value);
                int value = accumulator + memory_value;
                set_accumulator(&value);
            }
            else {
                sc_regSet(1, 1);
            }
            break;
        case 31: 
            if (operand > 0 && operand < MEMORY_SIZE) {
                int memory_value;
                sc_memoryGet(operand, &memory_value);
                int value = accumulator - memory_value;
                set_accumulator(&value);
            }
            else {
                sc_regSet(1, 1);
            }
            break;
        case 32: 
            if (operand > 0 && operand < MEMORY_SIZE) {
                int memory_value;
                sc_memoryGet(operand, &memory_value);

                if (memory_value == 0) {
                    sc_regSet(3, 1);
                    sc_regSet(5, 1);                    
                } else {
                    int value = accumulator / memory_value;
                    set_accumulator(&value);
                }
            }
            else {
                sc_regSet(1, 1);
            }
            break;
        case 33: 
            if (operand > 0 && operand < MEMORY_SIZE) {
                int memory_value;
                sc_memoryGet(operand, &memory_value);
                int value = accumulator * memory_value;
                set_accumulator(&value);
            }
            else {
                sc_regSet(1, 1);
            }
            break;
        case 51: 
        case 52: 
        case 53: 
        case 54: 
        case 60: 
        case 61: 
        case 62: 
        case 63: 
        case 64: 
        case 65: 
        case 66: 
        case 67: 
        case 68: 
        case 69: 
        case 70: 
        case 71: 
        case 72: 
        case 73: 
        case 74: 
        case 75: 
        case 76: break;
    }

    return 0;
}
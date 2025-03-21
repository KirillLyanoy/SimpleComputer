#include "mySimpleComputer.h"

int sc_memorySet(int address, int value) {
    if (address < 0 || address >= MEMORY_SIZE) {
        registr = registr | (1 << (MEMORY_OUT_OF_BOUNDS - 1));
        return -1;
    }
    else {
        sc_memory[address] = value;
        return 0;
    }
}
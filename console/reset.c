#include "console.h"

int reset() {

    sc_memoryInit();
    set_accumulator(0);
    set_instruction_counter(0);
    set_operation(0);

    sc_regSet(1, 0); // MEMORY_OUT_OF_BOUNDS
    sc_regSet(2, 0); // COMMAND_NOT_FOUND
    sc_regSet(3, 0); // DIVISION_BY_ZERO_ERROR
    sc_regSet(4, 0); // OVERFLOW_DURING_OPERATION
    sc_regSet(5, 1); // CLOCK_PULSES_IGNORED

    return 0;
}
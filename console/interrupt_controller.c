#include "console.h"

int interrupt_controller() {

    int clock_pulse_flag;
    sc_regGet(5, clock_pulse_flag);

    if (!clock_pulse_flag) {

    }


    return 0;
}


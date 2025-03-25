#include "console.h"

void clock_pulse_generator() {
    while(1) {
        sleep(500);
        raise(SIGALRM);
    }
}
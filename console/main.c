#include "console.h"

int main() {
    rk_mytermsave();
    int rows, cols;
    int accumulator = 0;

    int selected_cell_index = 0;
    int key;
    rk_mytermregime(0, 0, 1, 0, 1);
    sc_memoryInit();
    char file[] = "memory.txt";

    signal(SIGALRM, interrupt_controller);
    pthread_t clock_pulse_generator_thread;
    prhread_create(&clock_pulse_generator_thread, NULL, clock_pulse_generator, NULL);

    while(1) {
        mt_clrscr();



        draw_console(&rows, &cols);
        print_memory(sc_memory, selected_cell_index);
        print_accumulator(accumulator);
        print_instruction_counter(selected_cell_index);
        //print_operation();
        print_flags();
        
        fflush(stdout);

        rk_readkey(&key);

        if (37 <= key || key <= 40) {
            memory_cell_selection(key, &selected_cell_index);  
        } else {

#define KEY_I 9 
#define KEY_L 12 
#define KEY_R 18 
#define KEY_S 19 
#define KEY_T 20
            switch(key) {            
                case (9): //i 
                    
                case (12): //l 
                    sc_memoryLoad(file); break;
                case (18): //r 
                    reset(); break;
                case (19): //s 
                    sc_memorySave(file); break;                  
                case (20): //t 
                    break;
                case (41): //f5                
                    set_accumulator(&accumulator); break;
                case (42): //f6
                    set_instruction_counter(&selected_cell_index); break;
                case (43):
                    set_memory_cell(&selected_cell_index); break;
                default: break;
            }
        }
    }
    rk_mytermrestore();
    return 0;
}
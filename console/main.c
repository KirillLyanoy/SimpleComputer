#include "console.h"

int main() {
    reset();

    int rows, cols;
    print_console(&rows, &cols);

    int clock_pulse_flag;

    rk_mytermsave();

    int key;
    rk_mytermregime(0, 0, 1, 0, 1);
    sc_memoryInit();
    char file[] = "memory.txt";

    signal(SIGALRM, CU);
    pthread_t clock_pulse_generator_thread;
    pthread_create(&clock_pulse_generator_thread, NULL, clock_pulse_generator, NULL);    
    while(1) {
        sc_regGet(5, &clock_pulse_flag);
        print_console(&rows, &cols);
        rk_readkey(&key);
        if (37 <= key && key <= 40) {
            memory_cell_selection(key, &selected_cell_index);              
        } else {
            switch(key) {            
                case (9): //i                                          
                    reset(); break;
                case (10):  //enter
                    set_memory_cell();                       
                    break;
                case (12): //l 
                    sc_memoryLoad(file); break;
                case (18): //r                 
                    sc_regSet(5, 0);
                case (19): //s 
                    sc_memorySave(file); break;                  
                case (20): //t 
                    sc_regSet(5, 1);
                    break;
                case (27): //escape
                    break;
                case (41): { //f5    
                    if (clock_pulse_flag) set_accumulator(&accumulator); 
                    break;
                }
                case (42): { //f6
                    if (clock_pulse_flag) set_instruction_counter(&selected_cell_index); 
                        break;
                }
                case (43): {
                    if (clock_pulse_flag) set_memory_cell(&selected_cell_index); 
                        break;
                    }
                default: break;
            }
        }          
     
    }
    rk_mytermrestore();
    return 0;
}
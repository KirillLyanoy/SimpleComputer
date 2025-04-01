#include "console.h"

void CU(int signum) {
    
    int clock_pulse_flag;
    sc_regGet(5, &clock_pulse_flag);

    if (clock_pulse_flag == 0) {        
        
        int value;
        int temp_selected_cell_index = selected_cell_index;
        sc_memoryGet(temp_selected_cell_index, &value);                    

        if (((value >> 16) & 1) == 1) {
        
            int command;
            int operand;

            sc_commandDecode(value, &command, &operand);

            switch(command) {

                case 30: case 31: case 32: case 33: case 51: 
                case 52: case 53: case 54: case 60: case 61: 
                case 62: case 63: case 64: case 65: case 66: 
                case 67: case 68: case 69: case 70: case 71: 
                case 72: case 73: case 74: case 75: case 76:
                    ALU(command, operand); 
                    break;

                case 10: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        selected_cell_index = operand;
                        set_memory_cell();
                        break;
                    }
                case 11: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        int value;
                        sc_memoryGet(operand, &value);
                        printf("Cell %d value: %X", operand, value);
                        break;
                    }
                case 20: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        sc_memoryGet(operand, &accumulator);                       
                        break;
                    }
                case 21: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        sc_memorySet(operand, accumulator);                       
                        break;
                    }
                case 40: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        selected_cell_index = operand;                       
                        break;
                    }                
                case 41: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        if (accumulator < 0) {
                            selected_cell_index = operand;  
                        }                                             
                        break;
                    }  
                case 42: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        if (accumulator == 0) {
                            selected_cell_index = operand;  
                        }                                             
                        break;
                    }  
                case 43: 
                    sc_regSet(5, 1);
                    break;
                case 55: 
                    if (operand < 0 || operand >= MEMORY_SIZE) {
                        sc_regSet(1, 1);
                        sc_regSet(5, 1); 
                    }
                    else {
                        if (accumulator > 0) {
                            selected_cell_index = operand;  
                        }                                             
                        break;
                    }
                case 56: 
                    break;
                case 57: 
                    break;
                case 58: 
                    break;
                case 59:                    
                    break;

                default:
                    sc_regSet(5, 0);
                    sc_regSet(2, 1); 
                    break;
            }            
        }

        int rows, cols;
        print_console(&rows, &cols);

        if (selected_cell_index + 1 < MEMORY_SIZE)
            selected_cell_index += 1;
        else 
            selected_cell_index = 0;   

        
    }
}

#include "console.h"

int set_memory_cell() {
    if (selected_cell_index < 0 || selected_cell_index >= MEMORY_SIZE) return -1;                  
    int cell_value;
    rk_mytermrestore();
    printf("Cell memory value: ");
    while(1) {
        scanf("%d", &cell_value);          
        if (cell_value < 0 || cell_value > 131071) {
            printf("Invalid value. Repeat input: ");        
        } 
        else break;               
    }
    rk_mytermregime(0, 0, 1, 0, 1);

    sc_memorySet(selected_cell_index, cell_value);
    return 0;
}
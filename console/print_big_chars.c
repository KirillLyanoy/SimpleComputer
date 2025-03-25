#include "console.h"

int print_big_chars(int value) {
    
    int x = 14, y = 10;
    int digits[4];
    digits[0] = value / 1000,
    digits[1] = value / 100 - value / 1000 * 10;
    digits[2] = value / 10 - value / 100 * 10;
    digits[3] = value - value / 10 * 10;

    int big_symbol_0[2] = { BIG_SYMBOL_0 };
    int big_symbol_1[2] = { BIG_SYMBOL_1 };
    int big_symbol_2[2] = { BIG_SYMBOL_2 };
    int big_symbol_3[2] = { BIG_SYMBOL_3 };
    int big_symbol_4[2] = { BIG_SYMBOL_4 };
    int big_symbol_5[2] = { BIG_SYMBOL_5 };
    int big_symbol_6[2] = { BIG_SYMBOL_6 };
    int big_symbol_7[2] = { BIG_SYMBOL_7 };
    int big_symbol_8[2] = { BIG_SYMBOL_8 };
    int big_symbol_9[2] = { BIG_SYMBOL_9 };
    int big_symbol_plus[2] = { BIG_SYMBOL_PLUS };   

    bc_printbigchar(big_symbol_plus, x, 2, DEFAULT, DEFAULT); 
    
    for (int i = 0; i < 4; i++) {
        switch (digits[i]) {
            case (0): {           
                bc_printbigchar(big_symbol_0, x, y, DEFAULT, DEFAULT);                
                break; 
            };            
            case (1): { 
                bc_printbigchar(big_symbol_1, x, y, DEFAULT, DEFAULT); 
                break; 
            }
            case (2): { 
                bc_printbigchar(big_symbol_2, x, y, DEFAULT, DEFAULT); 
                break; 
            }  
            case (3): { 
                bc_printbigchar(big_symbol_3, x, y, DEFAULT, DEFAULT); 
                break; 
            }  
            case (4): { 
                bc_printbigchar(big_symbol_4, x, y, DEFAULT, DEFAULT); 
                break; 
            }  
            case (5): { 
                bc_printbigchar(big_symbol_5, x, y, DEFAULT, DEFAULT); 
                break; 
            }  
            case (6): { 
                bc_printbigchar(big_symbol_6, x, y, DEFAULT, DEFAULT); 
                break; 
            }  
            case (7): { 
                bc_printbigchar(big_symbol_7, x, y, DEFAULT, DEFAULT); 
                break; 
            }  
            case (8): { 
                bc_printbigchar(big_symbol_8, x, y, DEFAULT, DEFAULT); 
                break; 
            }  
            case (9): { 
                bc_printbigchar(big_symbol_9, x, y, DEFAULT, DEFAULT); 
                break; 
            }                       
            default: return -1;
        }            
        y += 8;     
    }
    return 0;
}
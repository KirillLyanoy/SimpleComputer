#ifndef __GUARD_MYSIMPLECOMPUTER_H
#define __GUARD_MYSIMPLECOMPUTER_H

#include <stdio.h>
#include <stdlib.h>

#define REGISTER_SIZE 2
#define MEMORY_SIZE 2

#define MEMORY_OUT_OF_BOUNDS 1         // 001
#define COMMAND_NOT_FOUND 2            // 010

extern int sc_memory[MEMORY_SIZE];
extern int registr;

int sc_memoryInit();

int sc_memorySet(int address, int value);

int sc_memoryGet(int address, int* value);

int sc_memorySave(char* filename);

int sc_memoryLoad(char* filename);

int sc_regInit(void);

int sc_regSet(int registrNum, int value);

int sc_regGet(int registrNum, int* value);

int sc_commandEncode(int command, int operand, int* value);

int sc_commandDecode(int value, int* command, int* operand);

#endif /* __GUARD_MYSIMPLECOMPUTER_H */
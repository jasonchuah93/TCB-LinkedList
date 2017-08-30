#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include <stdlib.h>

typedef struct TCB TCB;
struct TCB{
	TCB *next; //#0
	char *name; //#4
	void (*task)(void); //#8
	uint32_t *stackPointer; //#12
	uint32_t *stackBegin; //#16
	uint32_t stackSize; //#20
	uint32_t execReturnCode;  //LR on interrupt //#24
};

typedef struct StackRegister StackRegister;
struct StackRegister{
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R12;
	uint32_t LR;
	uint32_t PC;
	uint32_t xPSR;
};

TCB *createThread(char *name,void (*task)(void), uint32_t size);
TCB* initKernel(char *mainThreadName);

#endif //TASK_H

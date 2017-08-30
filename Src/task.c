#include <stdlib.h>
#include "Task.h"

TCB *createThread(char *name,void (*task)(void), uint32_t size){
	if(size < 128){
		size = 128;
	}
	TCB *tcb = (TCB*)malloc(sizeof(TCB));
	tcb->name = name;
	tcb->task = task;
	tcb->stackSize = size;
	tcb->stackBegin = (uint32_t*)malloc(size);
	tcb->execReturnCode = 0xfffffff9;
	tcb->stackPointer = tcb->stackBegin+size;
	tcb->stackPointer -=sizeof(StackRegister);
	StackRegister *sr = (StackRegister*)tcb->stackPointer;
	sr->R4 = 0x44444444;
	sr->R5 = 0x55555555;
	sr->R6 = 0x66666666;
	sr->R7 = 0x77777777;
	sr->R8 = 0x88888888;
	sr->R9 = 0x99999999;
	sr->R10 = 0xaaaaaaaa;
	sr->R11 = 0xbbbbbbbb;
	sr->R0 = 0x12340000;
	sr->R1 = 0x11111111;
	sr->R2 = 0x22222222;
	sr->R3 = 0x33333333;
	sr->R12 = 0xcccccccc;
	sr->LR = 0xeeeeeeee;
	sr->PC = (uint32_t)task;
	sr->xPSR = 0x21000000;

	return tcb;
}

TCB *initKernel(char *mainThreadName){
	TCB *tcb = (TCB*)malloc(sizeof(TCB));
	tcb->name = mainThreadName;
	tcb->stackSize = 0;
	tcb->stackBegin = NULL;
	return tcb;
}

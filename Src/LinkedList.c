#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"
#include "Task.h"

Element *createElement(char *name,void (*task)(void), uint32_t size){
	if(size < 128){
		size = 128;
	}
	LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
	list->name = name;
	list->task = task;
	list->stackSize = size;
	list->stackBegin = (uint32_t*)malloc(size);
	list->execReturnCode = 0xfffffff9;
	list->stackPointer = list->stackBegin+size;
	list->stackPointer -=sizeof(StackRegister);
	StackRegister *sr = (StackRegister*)list->stackPointer;
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
	return list;
}

LinkedList *createLinkedList(){
	LinkedList *list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

void *listAddFirst(Element *newElement, LinkedList *list){
	if(list->head == NULL && list->tail == NULL){
		list->head = list->tail = newElement;
		newElement -> next = NULL;
	}else{
		newElement->next=list->head;
		list->head=newElement;
	}
	list->length++;
}


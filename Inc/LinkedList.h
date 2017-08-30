#ifndef LinkedList_H
#define LinkedList_H

#include <stdint.h>

typedef struct Element_t{
	struct Element_t *next;
	char *name;
	void (*data)(void);
	uint8_t *stackPointer;
	uint8_t *stackBegin;
	uint8_t stackSize;
	uint32_t execReturnCode;
}Element;

typedef struct{
	Element *head;
	Element *tail;
}LinkedList;

LinkedList *createThread(char *name,void (*task)(void), uint32_t size);
LinkedList *initKernel(char *mainThreadName);
Element *createElement(void *fileInfo);
LinkedList *createLinkedList();
void *listAddFirst(Element *newElement, LinkedList *list);

#endif // LinkedList_H

#ifndef __stack_linkedlist_h
#define __stack_linkedlist_h

#include "LinkedList.h"

typedef struct __stack_linkedlist stack_list;

typedef struct __stack_linkedlist{
	List * list;
	void *stack_pointer;
	int length;
	int data_size;
}stack_list;

void stack_list_create (stack_list * a,int data_size);
void stack_list_destroy (stack_list *st);

void stack_list_push(stack_list *a, void *data);
void stack_list_pop(stack_list *st, void *res);

void stack_list_printAll( stack_list * st , void (*traverse)(void *));
void stack_list_clear(stack_list *st);


int stack_list_getLength (stack_list *st);
int stack_list_getCapacity (stack_list *st);


/*
int stack_list_peek(stack_list *st, void *res);
int stack_list_search(stack_list *st, void *key , int (*cmp) (const void *a, const void *b));
*/
#endif
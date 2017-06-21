#ifndef __stack_list_h
#define __stack_list_h
#include "LinearList.h"
typedef struct __stack_list stack_arr;

typedef struct __stack_list{
	Array * arr;
	void *stack_pointer;
	int capacity;
	int length;
	int data_size;
}stack_arr;

void stack_arr_create (stack_arr * a,int capacity ,int data_size);
void stack_arr_destroy (stack_arr *st);

void stack_arr_push(stack_arr *a, void *data);
void stack_arr_pop(stack_arr *st, void *res);
void stack_arr_printAll( stack_arr * st , void (*traverse)(void *));
int stack_arr_peek(stack_arr *st, void *res);
int stack_arr_search(stack_arr *st, void *key , int (*cmp) (const void *a, const void *b));
void stack_arr_clear(stack_arr *st);

int stack_arr_isEmpty(stack_arr *st);
int stack_arr_getLength (stack_arr *st);
int stack_arr_getCapacity (stack_arr *st);

#endif
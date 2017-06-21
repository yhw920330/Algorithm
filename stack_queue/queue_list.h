#ifndef __queue_arr_h
#define __queue_arr_h

#include "LinearList.h"

typedef struct __queue_arr queue_arr;

typedef struct __queue_arr{
	Array * arr;
	int length;
	int front_idx;
	int rear_idx;
	int capacity;
	int data_size;
}queue_arr;

void queue_arr_create (queue_arr * a,int capacity, int data_size);
void queue_arr_destroy (queue_arr *st);

void queue_arr_put(queue_arr *a, void *data);
void queue_arr_get(queue_arr *st);

void queue_arr_printAll( queue_arr * st , void (*traverse)(void *));
void queue_arr_clear(queue_arr *st);

int queue_arr_isEmpty(queue_arr *st);
int queue_arr_isFull(queue_arr *st);

int queue_arr_getLength (queue_arr *st);
int queue_arr_getCapacity (queue_arr *st);


/*
int queue_array_peek(queue_array *st, void *res);
int queue_array_search(queue_array *st, void *key , int (*cmp) (const void *a, const void *b));
*/
#endif
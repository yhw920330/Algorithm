#ifndef __queue_linkedlist_h
#define __queue_linkedlist_h

#include "LinkedList.h"

typedef struct __queue_linkedlist queue_list;

typedef struct __queue_linkedlist{
	List * list;
	int length;
	int data_size;
}queue_list;

void queue_list_create (queue_list * a,int data_size);
void queue_list_destroy (queue_list *st);

void queue_list_put(queue_list *a, void *data);
void queue_list_get(queue_list *st);

void queue_list_printAll( queue_list * st , void (*traverse)(void *));
void queue_list_clear(queue_list *st);


int queue_list_getLength (queue_list *st);
int queue_list_getCapacity (queue_list *st);
int queue_list_peek(queue_list *st, void *res);


/*
int queue_list_peek(queue_list *st, void *res);
int queue_list_search(queue_list *st, void *key , int (*cmp) (const void *a, const void *b));
*/
#endif
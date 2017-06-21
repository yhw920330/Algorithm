#ifndef __editer_h_
#define __editer_h_
#include "editer.h"
#include "LinearList.h"
#include "LinkedList.h"
#include "queue_linkedlist.h"
#include "queue_list.h"
#include "stack_linkedlist.h"
#include "stack_list.h"

#pragma warning (disable :4996)

void I_function (stack_list * a, int line);
void C_function (stack_list *e, queue_list *c, int a, int b);
void V_function (stack_list *e, queue_list *c);
void U_function (stack_list *e, stack_arr *d, int num);
void D_function (stack_list *e, stack_arr *d, int a, int b);
void S_Function(stack_list *e , char fn[20]);
void R_Function(stack_list *e , char fn[20]);

void L_function(stack_list *a , void (*print) (void *data)) ;
void traverseWithIndex (List * a, void (*print) (void *data));
void printListwithIndex (List *x);

#endif
#include "stack_linkedlist.h"
#include "LinkedList.h"


void stack_list_create (stack_list * st,int data_size){
	 
	 st->length = 0;
	 st->data_size= data_size;
	 st->list = (List *)malloc(sizeof(List)); 
	 Create(st->list, data_size);
	 st->stack_pointer = st->list->tail->llink;

}

void stack_list_push(stack_list *st, void *data){
	insert_push_back(st->list, data);
	(st->length) ++;
	st->stack_pointer = st->list->tail->llink;
}


void stack_list_pop(stack_list *st,void *res){
	if(st->length ==0){
		printf("Error :POP UnderFlow\n");
	}
	else{
	//	printf("stack_list_pop : ");	
	//	print_str(st->list->tail->llink->data);
		memcpy(res, st->list->tail->llink->data, st->list->data_size);
	//	print_str(res);
	delete_tail(st->list);
	(st->length) --;
	st->stack_pointer = st->list->tail->llink;
	}
}

void stack_list_printAll( stack_list * st , void (*traverse_)(void *)){
	traverse( st->list, traverse_);
}

void stack_list_clear(stack_list *st){
	deleteAll(st->list);
	st->length = 0;
	st->stack_pointer = st->list->head;
}



int stack_list_isEmpty(stack_list *st){
	if( st->length ==0){
		return 1;
	}
	else{
		return 0;
	}

}

int stack_list_getLength (stack_list *st){
	return st->length;
}


void stack_list_destroy (stack_list *st){
	stack_list_clear( st);
	if ( st-> list){
		free(st-> list);
	}
	st-> length =0;
	
}

#include "stack_list.h"
#include "LinearList.h"

void stack_arr_create (stack_arr * st, int capacity, int data_size){
	 st->capacity = capacity;
	 st->length = 0;
	 st->data_size= data_size;
	 st->arr = (Array *)malloc(sizeof(Array)); 
	 CreateArray(st->arr, capacity, data_size);
	 st->stack_pointer =(char*) st->arr ->front + data_size*(st->length-1);
}

void stack_arr_destroy (stack_arr *st){
	stack_arr_clear( st);
	if ( st-> arr){
		free(st-> arr);
	}
	st->capacity =0;
	st-> length =0;
	
}

void stack_arr_push(stack_arr *st, void *data){
	if(st->length < st->capacity){
	AppendArray(st->arr, data);
	(st->length) ++;
	st->stack_pointer = (char*) st->arr ->front + st->data_size*(st->length-1);
	}
	else{
		printf("Error :Push  Overflow\n");
	}
}

void stack_arr_pop(stack_arr *st ,void *res ){
	if(st->length ==0){
		printf("Error :POP UnderFlow\n");
	}
	else{
		memcpy(res, (char*)st->arr+ (st->length-1)*st->data_size, st->arr->element_size);
	DeleteIndexArray(st->arr, st->length-1);
	(st->length) --;
	st->stack_pointer = (char*) st->arr ->front +  st->data_size*(st->length-1);
	}
}

int stack_arr_peek(stack_arr *st, void *res){
	if(st->length ==0)
		return 0;
	else{
		memcpy(res, st->stack_pointer , st->arr->element_size);
		return 1;
	}

}
void stack_arr_printAll( stack_arr * st , void (*traverse)(void *)) {
	TraverseArray( st->arr, traverse);
}

int stack_arr_search(stack_arr *st, void *key , int (*cmp) (const void *a, const void *b)){
	int idx = SearchArray(st->arr, key, cmp);
	printf("Search Result :(index) %d \n", idx);
	return idx;
}

void stack_arr_clear(stack_arr *st){
	DeleteAllArray(st->arr);
	st->length = 0;
	st->stack_pointer = st->arr->front;
}

int stack_arr_isEmpty(stack_arr *st){
	if( st->length ==0){
		return 1;
	}
	else{
		return 0;
	}

}

int stack_arr_getLength (stack_arr *st){
	return st->length;
}

int stack_arr_getCapacity (stack_arr *st){
	return st->capacity;
}
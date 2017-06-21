#include "queue_list.h"
#include "LinearList.h"


void queue_arr_create (queue_arr * q,int capacity ,int data_size){
	 q->length = 0;
	 q->capacity = capacity;
	 q->data_size= data_size;
	 q->front_idx= 0;
	 q->rear_idx= 0;	 
	 q->arr = (Array *)malloc(sizeof(Array)); 
	 CreateArray(q->arr, capacity+1, data_size);
}

void queue_arr_put(queue_arr *q, void *data){
	if(queue_arr_isFull(q)){
		printf("Full ÀÔ´Ï´Ù!! ");
	}
	else{
		q->rear_idx= (q->rear_idx +1) %(q->capacity);
		memcpy( (char*)(q->arr->front) +(q->rear_idx)*q->data_size, data, q->arr->element_size);
		(q->length) ++;
	}
}


void queue_arr_get(queue_arr *q){
	if(q->length ==0){
		printf("Error :POP UnderFlow\n");
	}
	if(queue_arr_isEmpty(q)){
		printf("Error : Queue get- empty\n");
	}
	else{
		//delete_head(q->arr);
		q->front_idx  = (q->front_idx + 1 )% q->capacity;
		(q->length) --;
	}
}

void queue_arr_printAll( queue_arr * st , void (*traverse_)(void *)){
	int i;
	Array *self = st->arr;
	int element_size = self -> element_size; 
	printf(" front %d rear %d\n", st->front_idx, st->rear_idx);
	if( st->front_idx < st-> rear_idx){
		for(i=st->front_idx+1; i<=st->rear_idx; i++){
			printf("[%d ] :",i);
			traverse_((char*)self->front + i*element_size);
		}
	}
	else{
		for(i=st->front_idx+1; i<= st->capacity; i++){
			traverse_((char*)self->front + i*element_size);
		}
		for(i=1; i<= st->rear_idx; i++){
			traverse_((char*)self->front + i*element_size);
		}
	}
}


	

void queue_arr_clear(queue_arr *st){
	DeleteAllArray(st->arr);
	st->length = 0;
}

int queue_arr_isEmpty(queue_arr *st){
	
	if( st->front_idx == st->rear_idx){
		printf("Empty by idx=0");
		return 1;
	}
	else if(st->length ==0){
		printf("Empty by length =0");
		return 1;
	}
	else{
		return 0;
	}
}

int queue_arr_isFull(queue_arr *st){

	if( st-> front_idx == (st-> rear_idx + 1) % (st->capacity)){
		printf("Queue Full");
		return 1;
	}
	else if( st-> length == st-> capacity ){
		printf("Queue FULL~");
		return 1;
	}
	else 
		return 0;
}

int queue_arr_getLength (queue_arr *st){
	return st->length;
}


void queue_arr_destroy (queue_arr *st){
	queue_arr_clear( st);
	if ( st-> arr){
		free(st-> arr);
	}
	st-> length =0;
	
}


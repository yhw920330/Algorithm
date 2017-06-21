#include "queue_linkedlist.h"
#include "LinkedList.h"


void queue_list_create (queue_list * q,int data_size){
	 q->length = 0;
	 q->data_size= data_size;
	 q->list = (List *)malloc(sizeof(List)); 
	 Create(q->list, data_size);
}

void queue_list_put(queue_list *q, void *data){
	insert_push_back(q->list, data);
	(q->length) ++;
}


void queue_list_get(queue_list *q){
	if(q->length ==0){
		printf("Error :POP UnderFlow\n");
	}
	else{
	delete_head(q->list);
	(q->length) --;
	}
}

void queue_list_printAll( queue_list * st , void (*traverse_)(void *)){
	traverse( st->list, traverse_);
}

void queue_list_clear(queue_list *st){
	deleteAll(st->list);
	st->length = 0;
}

int queue_list_isEmpty(queue_list *st){
	if( st->length ==0){
		return 1;
	}
	else{
		return 0;
	}

}

int queue_list_getLength (queue_list *st){
	return st->length;
}


void queue_list_destroy (queue_list *st){
	queue_list_clear( st);
	if ( st-> list){
		free(st-> list);
	}
	st-> length =0;
	
}

int queue_list_peek(queue_list *st, void *res){
	int data_size= st->data_size;
	printf("%d : data_size",data_size);
	print_str(st->list->head->rlink->data);
	if(queue_list_isEmpty){
		return 0;	
	}
	else{
		res= malloc(data_size);
		printf("Peek ÇÔ¼ö");
		print_str(st->list->head->rlink->data);
		memcpy(res,st->list->head->rlink->data,data_size);
		return 1;

	}
}
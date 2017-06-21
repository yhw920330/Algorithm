#include "LinkedList.h"

void Create (List * a ,int node_size){
	a->head = (Node *) malloc(sizeof(Node));
	a->tail = (Node *) malloc (sizeof(Node));
	a->head->rlink= a->tail;
	a->head->llink=NULL;
	a->tail->rlink=NULL;
	a->tail->llink=a->head;

	a->length =0;
	a->data_size = node_size;
	a->current = NULL;




	//함수 포인터 
	a-> DestroyLinkedList = DestroyLinkedList;
	a-> insert_push_front=insert_push_front;
	a->insert_push_back =insert_push_back;
	a->insert_push_right =insert_push_right;
	a->insert_push_left = insert_push_left;
	a->delete_head = delete_head;
	a->delete_tail = delete_tail;
	a->delete_right = delete_right;
	a->delete_left =delete_left;
	a->deleteAll = deleteAll;
	a->sortedInsert = sortedInsert;
	a->traverse = traverse;
	//a->getNode = getNode;//current  Node 값을 
	//a->setNode  = setNode;
	a-> getLength = getLength;
	a->print_int = print_int;
	a-> cmp_int =cmp_int;
	a->print_str = print_str;
	a-> cmp_str = cmp_str;
	//
}
void DestroyLinkedList(List * a){
	deleteAll(a);
	if( a-> head)
	{
		a->head-> rlink = NULL;
		a->head -> llink = NULL;
		free(a->head);

	}
	if( a-> tail){
		a-> tail -> rlink= NULL;
		a-> tail -> llink = NULL;
		free(a-> tail);
	}
}

void insert_push_front( List * a, void *data){
	//Node *prev_front=NULL;
	
	Node * obj = (Node *) malloc (sizeof(Node));
	obj->data = malloc(a->data_size);
	memcpy(obj->data, data,a->data_size);

	obj->rlink = a->head->rlink;
	obj->llink = a->head;

	a->head->rlink->llink = obj;
	a->head->rlink = obj;

	//
	(a->length)++;
}
void insert_push_back( List * a, void *data){
	Node *obj = (Node *)malloc(sizeof(Node));
	obj -> data  = malloc(a->data_size);
	memcpy(obj->data, data, a->data_size);
	obj->rlink = a->tail;
	obj->llink = a->tail -> llink;

	a->tail->llink->rlink = obj;
	a->tail->llink = obj;
	
	(a->length)++;

}
void insert_push_right( List * a, void * prev, void *data, int (*cmp) (void *, void*)){
	//예외처리 안함 
	Node * head =  a-> head;
	Node * tail =  a-> tail;
	Node  * prevNode = head;
	Node * obj ; 

	prevNode = head->rlink;
	while(prevNode != tail ){
		if(cmp( prevNode-> data, prev) ==0){
			break;
		}
		prevNode = prevNode->rlink;
	}
	
	obj = (Node *) malloc (sizeof (Node));
	obj -> data = malloc( a-> data_size);
	memcpy(obj -> data, data, a->data_size);

	obj -> rlink = prevNode -> rlink;
	obj -> llink = prevNode;

	prevNode -> rlink -> llink = obj;
	prevNode -> rlink  = obj;

	(a-> length)++;
}
void insert_push_left(List * a, void * next, void *data, int (*cmp) (void *, void*)){
	Node * head =  a-> head;
	Node * tail =  a-> tail;
	Node  * prevNode = head;
	Node * obj ; 

	prevNode = head->rlink;
	while(prevNode != tail ){
		if(cmp( prevNode-> data, next) ==0){
			break;
		}
		prevNode = prevNode->rlink;
	}
	
	obj = (Node *) malloc (sizeof (Node));
	obj -> data = malloc( a-> data_size);
	memcpy(obj -> data, data, a->data_size);

	obj-> rlink = prevNode;
	obj -> llink = prevNode -> llink;

	prevNode -> llink -> rlink = obj;
	prevNode -> llink = obj;

	(a-> length) ++;

	
}

void delete_head(List * a){
	Node * head = a-> head;
	Node * tail = a-> tail;
	Node * todelete = a-> head->rlink;


	if(a->length >0 && todelete != tail){
		todelete->rlink->llink = head;
		head -> rlink = todelete-> rlink;
		todelete->rlink = NULL;
		todelete->llink = NULL;
		free(todelete);
		(a->length)--;
	}

}

void delete_tail(List * a){
	Node * head = a-> head;
	Node * tail = a-> tail;
	Node * todelete = tail->llink;

	if( a-> length>0 && todelete != head){
		todelete->llink->rlink = tail;
		tail->llink = todelete->llink;
		todelete->llink = NULL;
		todelete->rlink = NULL;
		free(todelete);
		(a->length) --;
	}


}
void delete_right(List * a, void *prev, int (*cmp) (void *, void *)){

	Node * head =  a-> head;
	Node * tail =  a-> tail;
	Node  * prevNode = head;
	Node * todelete;
	prevNode = head->rlink;

	while(prevNode != tail ){
		if(cmp( prevNode-> data, prev) ==0){
			break;
		}
		prevNode = prevNode->rlink;
	}

	todelete = prevNode->rlink;
	if( prevNode != tail && todelete != tail){
		todelete ->rlink -> llink = prevNode;
		prevNode -> rlink = todelete->rlink;
		todelete -> llink= NULL;
		todelete -> rlink = NULL;
		free(todelete);
		(a->length) --;
	}

}
void delete_left(List * a, void *next, int (*cmp) (void *, void *) ){
	
	Node * head =  a-> head;
	Node * tail =  a-> tail;
	Node  * prevNode = head;
	Node * todelete;
	prevNode = head->rlink;

	while(prevNode != tail ){
		if(cmp( prevNode-> data, next) ==0){
			break;
		}
		prevNode = prevNode->rlink;
	}

	todelete = prevNode->llink;
	if( prevNode != tail && todelete != head ){
		todelete -> llink -> rlink = prevNode;
		prevNode -> llink = todelete->llink;
		todelete -> llink= NULL;
		todelete -> rlink = NULL;
		free(todelete);
		(a->length) --;
	}

}
void deleteAll(List * a){
	int i= a->length;;
	while(i--){
		delete_head(a);
	}
}

void sortedInsert(List * a, void *data , int (*cmp) (void * a, void *b)){
	
	Node * head = a-> head;
	Node * tail = a-> tail;
	Node * tp = head;
	void * next_value =malloc(a->data_size);

	int i, len = a-> length;
	for(i=0; i<len; i++){
		tp= tp-> rlink;
		if(cmp (tp-> data, data)>0){
			memcpy(next_value, tp-> data, a->data_size);
			break;
		}
	}
	//tp 10 20 30
	insert_push_left(a,next_value, data,cmp);


}

void traverse(List * a, void (*print) (void *data)){
	int len = a-> length;
	int size = a-> data_size;
	Node *h = a->head;
	Node *t = a->tail;
	Node *tp = h;
	while(1){
		tp= tp->rlink;
		if(tp == t){
			break;
		}
		print(tp->data);
	}
	printf("\n");
}
void print_int(void *data){
	printf("%d ", *(int *) data);
}
/*
int cmp_int(void * a, void *b){
	return ( *(int *)a) - (*(int*)b) ; 
}
*/


void print_str(void *data){
	printf("%-10s\n", (char *) data);
}

/*
int cmp_str(void * a, void *b){
	return strcmp( ( char *) a, (char*)b);
}
*/
void getNode( List *);//current  Node 값을 
void setNode(List *, void *data);

int getLength(List * a){
	return a->length;
}


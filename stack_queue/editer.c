#include "editer.h"


void I_function (stack_list * a, int line){
	char tp[81];
	printf("   %d :",line);
	fflush(stdin);
	gets(tp);
	if(strlen(tp)==0){
		printf("   Error : Input Text\n");
		return;
	}
	stack_list_push(a, tp);
	//a->length++;
	//stack_list_printAll(a, print_str);
}

void C_function (stack_list *e, queue_list *c, int a, int b){
	Node * tp = e -> list-> head;
	int i,j;
	queue_list_clear(c);
	if( (a+b-1) > e->length)
	{
		printf("Copy Error: 현재 %d\n",e->length);
		return ;
	}
	for(i=1; i<=a; i++){
		tp = tp-> rlink;
	}
	//
	for(j=a; j<= a+b-1; j++){

		printf("   Copy Data :");  print_str(tp-> data);
	
		if(tp == e->list->tail){
	//	printf("tail!!\n");
			break;
		}

		queue_list_put(c,tp->data);		
		tp= tp->rlink;

	}
	//
	
}



void V_function (stack_list *e, queue_list *c){

	List *a = c->list;
	Node *h = a->head;
	Node *t = a->tail;
	Node *tp = h;
	
	while(1){
		tp= tp->rlink;
		if(tp == t){
			break;
		}
		printf("   Paste Data : %s\n", tp->data);
		stack_list_push(e,tp->data);
		//e->length++;
	}

}

void U_function (stack_list *e, stack_arr *d, int num){
	void *res= malloc(e->data_size);
	int i;
	for(i=num; i>0; i--){
		stack_arr_peek(d,res);
		stack_list_push(e,res);
	//	e->length++;
		stack_arr_pop(d,res);
	}


}

void D_function (stack_list *e, stack_arr *d, int a, int b){
	stack_list tmp,tmp_delete;
	void * res = malloc(e->data_size);
	int i,j;
	int len  =e->length;

	Node * tp = e -> list-> head;
	j = e->length;
	if(a+b-1 > e->length){
		printf("Delete Error : 현재 %d line\n", e->length);
		return;
	}
	stack_list_create(&tmp,e->data_size);
	stack_list_create(&tmp_delete,e->data_size);

	while(len > a+b-1){
		stack_list_pop(e,res);
		stack_list_push(&tmp,res);
		len--;
	}

	/*
	for(i=a+b-1; i>=a; i--){
	stack_list_pop(e,res);
	e->length--;
	stack_list_push(&tmp_delete,res);
	}
	for(i=a+b-1; i>=a; i--){
	stack_list_pop(&tmp_delete,res);
	stack_arr_push(d,res);
	d->length++;
	}
	*/

	for(i=a+b-1; i>=a; i--){
		stack_list_pop(e,res);
		stack_arr_push(d,res);
		//e->length--;
	}

	///////////////////
	for(i=j; i>a+b-1; i--){
		stack_list_pop(&tmp,res);
		stack_list_push(e,res);
	}
	
	//
	stack_list_destroy(&tmp);
	stack_list_destroy(&tmp_delete);


}

void L_function(stack_list *a , void (*print) (void *data) ){
	traverseWithIndex(a->list,print);
}

void S_Function(stack_list *e , char fn[20]){
	FILE *fp;
	int i =1;
	int len = e-> length;
	int size = e-> data_size;
	Node *h = e->list->head;
	Node *t = e->list->tail;
	Node *tp = h;

	fp = fopen(fn,"wt");
	if(fp==NULL){
		printf("File Open Error\n");
	}


	while(1){
		tp= tp->rlink;
		if(tp == t){
			break;
		}
		fprintf(fp,"%s\n",tp->data);
	}

	printf("   Output >> %s (data : %d개)\n", fn,e->length);
	fclose(fp);
	


}

void R_Function(stack_list *e , char fn[20]){
	FILE *fp;
	char full[100];
	char line[81];
	fp = fopen(fn,"rt+");
	if(fp==NULL){
		printf("File Open Error\n");
	}

	stack_list_clear(e);
	while(!feof(fp)){
		//선별적으로 읽기 - [%*]을 사용하면 값을 읽지 않는다.
		fscanf(fp,"%[^\n]\n",full);
		if(strlen(full)==0)
			break;
		stack_list_push(e,full);
		//e->length++;
	}
	fclose(fp);
}

void traverseWithIndex (List * a, void (*print) (void *data)){
	int len = a-> length;
	int size = a-> data_size;
	Node *h = a->head;
	Node *t = a->tail;
	Node *tp = h;
	int i=1;
	
	printf("   -------------------------------------\n");
	printf("   line :   content \n");
	printf("   -------------------------------------\n");
	while(1){
		tp= tp->rlink;
		if(tp == t){
			break;
		}
		printf("   [%2d] :",i++);
		print(tp->data);
	}
	printf("\n");
}


void printListwithIndex (List *x){
	traverseWithIndex(x,print_str);
}


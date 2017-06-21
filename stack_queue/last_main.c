#include "LinearList.h"
#include "LinkedList.h"
#include "queue_linkedlist.h"
#include "queue_list.h"
#include "stack_linkedlist.h"
#include "stack_list.h"
/*
int main(){
	stack_arr st_a;
	stack_arr st_aa;
	stack_list st_l_s;

	queue_list q_l_s;
	queue_arr q_a_i;

	int x[10]= {0,1,2,3,4,5,6,7,8,9};
	char xx[][20] ={"00","11","22","33","44","55","66","88","99"};
	int peek_res=-1;

	queue_arr_create(&q_a_i,5,sizeof(int));
	queue_arr_put(&q_a_i, &x[1]);
	queue_arr_put(&q_a_i, &x[2]);
	queue_arr_printAll(&q_a_i, print_int);


	queue_list_create(&q_l_s,sizeof(xx[0]));
	queue_list_put(&q_l_s, &xx[1]);
	queue_list_put(&q_l_s, &xx[2]);
	queue_list_printAll(&q_l_s, print_str);
	
	queue_list_get(&q_l_s);
	queue_list_printAll(&q_l_s, print_str);
	
	queue_list_put(&q_l_s, &xx[3]);
	queue_list_put(&q_l_s, &xx[4]);
	queue_list_printAll(&q_l_s, print_str);

	printf("---------");
	queue_list_clear(&q_l_s);
	printf("Len : %d ", queue_list_getLength(&q_l_s));
	queue_list_destroy (&q_l_s);

	
	stack_list_create(&st_l_s,sizeof(xx[0]));
	stack_list_push(&st_l_s, &xx[0]);
	stack_list_push(&st_l_s, &xx[2]);
	stack_list_printAll(&st_l_s, print_str);
	
	//stack_list_pop(&st_l_s);
	stack_list_printAll(&st_l_s, print_str);
	
	stack_list_push(&st_l_s, &xx[0]);
	stack_list_push(&st_l_s, &xx[2]);
	stack_list_printAll(&st_l_s, print_str);

	printf("---------");
	stack_list_clear(&st_l_s);
	printf("Len : %d ", stack_list_getLength(&st_l_s));
	stack_list_destroy (&st_l_s);
	
	stack_arr_create(&st_a, 10, sizeof(int));
	stack_arr_create(&st_aa, 10, sizeof(xx[0]));
	stack_arr_push(&st_aa, &xx[0]);
	stack_arr_printAll(&st_aa, print_str);
	

	stack_arr_push(&st_a, &x[0]);
	stack_arr_push(&st_a, &x[3]);
	stack_arr_printAll(&st_a, print_int);
	
	stack_arr_pop(&st_a);
	stack_arr_printAll(&st_a, print_int);
	
	stack_arr_push(&st_a, &x[2]);
	stack_arr_printAll(&st_a, print_int);

	printf("peek test\n");
	if(stack_arr_peek(&st_a, &peek_res))
		printf("\nPeek data: %d\n", peek_res);

	printf("search test\n");
	stack_arr_search(&st_a,&x[0], cmp_int);
	stack_arr_search(&st_a,&x[7], cmp_int);

	printf("Len : %d Capa :%d\n", stack_arr_getLength(&st_a), stack_arr_getCapacity(&st_a));
		
	printf("clear test\n");
	stack_arr_clear( &st_a);
	stack_arr_printAll(&st_a, print_int);

	printf("get Capacity\n");
	printf("Len : %d Capa :%d\n", stack_arr_getLength(&st_a), stack_arr_getCapacity(&st_a));
	
	stack_arr_destroy(&st_a);
	

	return 0;
}*/
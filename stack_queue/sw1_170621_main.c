#include "LinearList.h"
#include "LinkedList.h"
#include "queue_linkedlist.h"
#include "queue_list.h"
#include "stack_linkedlist.h"
#include "stack_list.h"
#include "editer.h"

#define DELETEBUFFER 10


int main(){
	//�����
	stack_list editor_stack_list; //���ο�����
	queue_list copy_queue_list ; // ���系��
	stack_arr delete_stack_arr;//���� ����

	char menu;
	int exit_flag=0;
	int from, size;
	void *res = malloc(81);
	//stack queue���
	stack_list_create(&editor_stack_list,sizeof(char[81]));
	queue_list_create(&copy_queue_list,sizeof(char[81]));
	stack_arr_create(&delete_stack_arr, DELETEBUFFER, sizeof(char[81]));

	printf(" --------------Hello Editer-------------------\n");
	while(1){
		printf(">>>");
		fflush(stdin);
		scanf("%c",&menu);
		switch(menu){
		case 'I':
		case 'i':
			//
			I_function(&editor_stack_list, editor_stack_list.length+1);
			break;
		case 'C':
		case 'c':
			scanf("%d %d", &from, &size);
			C_function(&editor_stack_list,&copy_queue_list,from,size);
			break;
		case 'D':
		case 'd':
			scanf("%d %d", &from, &size);
			D_function(&editor_stack_list,&delete_stack_arr,from,size);
			break;

		case 'V': 
		case 'v':
			V_function(&editor_stack_list,&copy_queue_list);
			break;
		case 'U':
		case 'u':
			scanf("%d",&size);
			U_function(&editor_stack_list,&delete_stack_arr,size);
			break;
		case 'L':
		case 'l':
			L_function(&editor_stack_list, print_str);
			break;

		case 'S':
		case 's':
			S_Function(&editor_stack_list,"editer_data.txt");
			break;

		case 'R':
		case 'r':
			R_Function(&editor_stack_list , "editer_data.txt");
			break;

		case 'X':
		case 'x':
			exit_flag=1;
			break;
		default :printf("  �ٽ� �Է��ϼ���(I, C, V, D, U, S,R,X)\n");
		}

		if(exit_flag==1){
			break;
		}
	}
	printf(" --------------Good Bye-------------------\n");
	return 0;
}
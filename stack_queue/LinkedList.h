#ifndef __Link_List_H_
#define __Link_List_H_

#include <stdio.h>
#include <stdlib.h>
#include < memory.h>
#include <string.h>
typedef struct __Node Node;
typedef struct __Node{
	void *data;
	Node *llink;
	Node *rlink;
}Node;

typedef struct _List List;
typedef struct _List{
	Node *head;
	Node *tail;
	int length;
	int data_size; // node의 바이트 크기 
	Node *current;



	//
	void (*DestroyLinkedList)(List *);
	void (*insert_push_front)( List *, void *data);
	void (*insert_push_back)( List *, void *data);
	void (*insert_push_right)( List *, void * prev, void *data, int (*cmp) (void *, void*));
	void (*insert_push_left)(List *, void * next, void *data , int (*cmp) (void *, void*) );

	void (*delete_head)(List *);
	void (*delete_tail)(List *);
	void (*delete_right)(List *, void *prev , int (*cmp) (void *, void *));
	void (*delete_left)(List *, void *next , int (*cmp) (void *, void *));
	void (*deleteAll)(List *);

	void (*sortedInsert)(List *, void *data, int (*cmp) (void * a, void *b));

	void (*traverse) (List * ,void (*print) (void *data));

	void (*getNode) (List *); //current  Node 값을 
	void (*setNode) (List *, void *data);

	int (*getLength) (List *);

	void (*print_int) (void *data);
	int (*cmp_int )(void * a, void *b);

	void (*print_str) (void *data);
	int (*cmp_str )(void * a, void *b);




	//
}List;


void Create (List * ,int node_size);
void DestroyLinkedList(List *);


int isExist(List *, void * key, int (*cmp) (void *a, void *b));
void insert_push_front( List *, void *data);
void insert_push_back( List *, void *data);
void insert_push_right( List *, void * prev, void *data, int (*cmp) (void *, void*));
void insert_push_left(List *, void * next, void *data , int (*cmp) (void *, void*) );

void delete_head(List *);
void delete_tail(List *);
void delete_right(List *, void *prev , int (*cmp) (void *, void *));
void delete_left(List *, void *next , int (*cmp) (void *, void *));
void deleteAll(List *);

void sortedInsert(List *, void *data, int (*cmp) (void * a, void *b));

void traverse(List * ,void (*print) (void *data));

void getNode (List *); //current  Node 값을 
void setNode (List *, void *data);

int getLength(List *);

void print_int(void *data);
int cmp_int(const void * a, const void *b);

void print_str(void *data);
int cmp_str(const void * a, const void *b);


#endif
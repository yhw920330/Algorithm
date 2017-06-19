#ifndef __linear_list_H
#define __linear_list_H

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct _Array Array;
typedef struct _Array {
	void * front;
	void * rear;
	int capacity;
	int length;

	int element_size;


	//함수 포인터 
	void (*Destroy) ( Array *self);
	int (*AppendArray) (Array *self, void* data); // return 성공 유무 -> overflow

	int (*InsertArray )(Array *self, void * prev_data, void * data, int (*com) (const void *a, const void *b)); // 
	int (*InsertIndexArray)( Array *self, int index, void * data);

	int (*DeleteArray) (Array *self, void * data , int (*cmp) ( const void *, const void*)); //return 성공 유무 --> 없는 데이터
	int (*DeleteIndexArray) (Array *self, int idx); // return 성공 유무 --> undefflow
	void (*DeleteAllArray)(Array *self);

	void (*SortArray)(Array *self,int (*cmp_func) (const void *, const void *)); // ascending 


	int (*cmp_int) ( const void *a, const void *b);
	int (*cmp_str) ( const void *a, const void *b);
	
	int (*SearchArray)(Array *self, void *, int (*cmp)(const void *, const void *)); // index 반환 

	void (*TraverseArray)(Array *self, void (*traverse)(void *));


	void* (*GetData)(Array *self, int index, void *data);
	void (*SetData)(Array *self, int index, void *data);

	int(* GetCapacity)(Array *self);
	int (*GetLength) (Array* self);

	void (*print_int) (void * x);
	void (*print_str) (void *x);


}Array; //선형 리스트 관리 구조 
//
void CreateArray(Array *self, int Capacity, int element_size); // length를 0으로 
//
void Destroy ( Array *self);
int AppendArray (Array *self, void*  data); // return 성공 유무 -> overflow

//
int InsertArray(Array *self, void * prev_data, void * data, int (*com) (const void *a, const void *b)); // 
int InsertIndexArray( Array *self, int index, void * data);

int DeleteArray(Array *self, void * data, int (*cmp ) (const void *, const void *)); //return 성공 유무 --> 없는 데이터
int DeleteIndexArray (Array *self, int idx); // return 성공 유무 --> undefflow
void DeleteAllArray(Array *self);

//
void SortArray(Array *self , int (*cmp_func) (const void *, const void *)); // ascending 
int SearchArray(Array *self, void * data, int (*com) (const void *, const void *)); // index 반환 
//void TraverseArray(Array *self);  
void TraverseArray(Array *self , void (*traverse)( void * c ));  

void Traverse_Int(Array *self);
void Traverse_Str(Array *self);


void* GetData(Array *self, int index, void* data); //나중에  데이터 써야되니까
void SetData(Array *self, int index, void* data);

int GetCapacity(Array *self);
int GetLength(Array* self);

int cmp_int ( const void *a, const void *b);
int cmp_str ( const void *a, const void *b);
void print_int(void * x);
void print_str(void *x);

#endif
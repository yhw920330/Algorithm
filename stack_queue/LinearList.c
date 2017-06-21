#include "LinearList.h"
#define FAIL -1
#define SUCCESS 1

void CreateArray(Array *self, int Capacity , int element_size){ 
	self -> front  = malloc (element_size * Capacity);
	self -> rear = (char *) self-> front + element_size * (Capacity-1);


	self -> element_size = element_size;
	self -> capacity = Capacity;
	self -> length= 0;


	// 함수 포인터 연결 
	self -> Destroy  =Destroy;
	self -> AppendArray  = AppendArray;// return 성공 유무 -> overflow
	self -> InsertArray  = InsertArray; // 
	self -> InsertIndexArray =InsertIndexArray;
	self -> DeleteArray = DeleteArray;//return 성공 유무 --> 없는 데이터
	self -> DeleteIndexArray = DeleteIndexArray; // return 성공 유무 --> undefflow
	self -> DeleteAllArray = DeleteAllArray;
	self -> SortArray = SortArray; // ascending 
	self -> SearchArray  = SearchArray; // index 반환 
	self -> TraverseArray = TraverseArray;
	self -> GetData =GetData;
	self -> SetData = SetData;
	self -> GetCapacity = GetCapacity;
	self -> GetLength =GetLength ;
	self -> cmp_int = cmp_int;
	self -> cmp_str = cmp_str;
	self -> Traverse_Int = Traverse_Int;
	self -> Traverse_Str = Traverse_Str;


	//	printf(" a: %p + a[rear] = %d\n",self->front, self ->rear);
} // length를 0으로 

void Destroy ( Array *self){
	 self -> capacity = 0;

	 if( self -> front ){
		free( self -> front);
	 }
	 
	 self -> length = 0; 
	 self -> front = NULL;
	 self -> rear = NULL;
}

int AppendArray (Array *self, void * data ){
	int check_overflow;
	
	if(self->length < self -> capacity){ 
		//memecpcy a 선언 
		memcpy( (char *)  (self ->front) + (self->length)*(self-> element_size), data, self->element_size);
		self -> length ++;
		check_overflow = SUCCESS;
	}
	else{
		check_overflow = FAIL;
	}


	return check_overflow;

	
} // return 성공 유무 -> overflow


int InsertArray(Array *self, void* prev, void * data, int (*com) (const void *a, const void *b)){
	int check_overflow;
	int i;
	void *tp = malloc(sizeof(self-> element_size));
	
	int size= self -> element_size;
	int len= self-> length;

	int find_indx= SearchArray(self, prev, com);

	check_overflow= FAIL;
	
	//printf("삽입 위치 : %d\n", find_indx);

	if(find_indx >=0 && len < self-> capacity){
		for( i= len; i>=find_indx+1; i--){
			memcpy( (char*) (self-> front) + i*size, (char*) self->front + (i-1) *size, size);
		}
		memcpy((char*) self ->front + size *(find_indx+1), data,size);
		(self -> length) ++;
		check_overflow = SUCCESS;
	}

	else{
		check_overflow =FAIL;
	}
	return check_overflow;
} // 


int InsertIndexArray( Array *self, int index, void * data){
	int i,check_overflow;
	int len = self-> length;
	int size= self ->element_size;
	//printf("index : %d  \t len : %d capa: %d",index,len,self->capacity);
	if((index >= -1)  &&(index < len) && (len < self-> capacity) ){
	//	for(j=len; j>index+1; j--){
	//		a[j] = a[j-1];
	//	}

		///

		for( i= len; i>=index+1; i--){
			memcpy( (char*) (self-> front) + i*size, (char*) self->front + (i-1) *size, size);
		}
		//
		
        memcpy((char*) self ->front + size *(index+1), data,size);
		print_int((char*) self ->front + size *(index+1));
		printf("<<");
		(self -> length) ++;
		check_overflow= SUCCESS;
	}
	else{
		check_overflow = FAIL;
	}

	return check_overflow;
}

////////////////

int DeleteArray(Array *self, void *data, int (*cmp) (const void *a, const void *b))
{ 
	int check ;
	int len = self-> length;
	int size = self -> element_size;
	int i, j;

	for(i=0; i< len;  i++){
		if( cmp( (char *) self -> front + i * size,  data) ==0)
		{
		//if(a[i] == data){
			for(j=i; j<len-1; j++){

				//a[j] = a[j+1]
				memcpy( (char *) self -> front + j * size, (char *) self -> front+ (j+1) *size, size);
			}
			(self-> length) --;
			check = SUCCESS;
		}
	}
	
	if( i==len) {
		check = FAIL;
	}
	return check;
} //return 성공 유무 --> 없는 데이터

int DeleteIndexArray (Array *self, int idx){ 
	int check_idx;
	int len = self -> length;
	int size= self -> element_size;
	int i;

	//int *a= self-> front;
	if( idx >= 0 && idx < len ){
		for( i= idx ; i<len; i++){
		//	a[i] = a[i+1];
			memcpy( (char *) self -> front +i*size, (char*) self -> front + (i+1) *size, size);
		}
		(self->length) --;
		check_idx=SUCCESS;
	}
	else {
	//	printf(" Error : Delete Index Array (idx : %d, length : %d)오류\n", idx, len);   
		check_idx= FAIL;
	}

	return check_idx;
} // return 성공 유무 --> undefflow

void DeleteAllArray(Array *self){ 
	int i;
	int len = self -> length;
	for(i = len -1; i>=0; i--) {
		DeleteIndexArray(self,i);
	}
	
}


void SortArray(Array *arr , int (*cmp_func) (const void *, const void *)){ 
	int i,j,k;
	int loopMax ;
	int innerLoop;
	int element_size;
	void * tp = malloc( arr-> element_size);
	loopMax = arr-> length  -1;
	element_size = arr-> element_size;
	
	for(i=0; i< loopMax ; i++){
		k=0;
		innerLoop = loopMax -i;
		for(j=0; j<innerLoop; j++){
			if( cmp_func( (char *)arr + j*element_size, (char *) arr+ (j+1)*element_size)   >0 ) {
				memcpy(tp, (char *) arr +  j * element_size, element_size);
				memcpy((char *) arr +  j * element_size ,	(char *) arr +  (j +1) * element_size, element_size); 
				memcpy((char *) arr +  (j+1) * element_size, tp, element_size);
				k=1;
			}
		}
		if(k==0)
			i=loopMax;
	}


	////
//	for(i=0; i < len; i++){
//		min_idx=i;
//		for(j=i+1; j<len; j++){
//			if( a[min_idx] > a[j]){
//				min_idx=j;
//			}
//		}
//		tp= a[min_idx];
//		a[min_idx]= a[i];
//		a[i] = tp;
//	}
} // ascending 

//

///

int cmp_int ( const void *a, const void *b){
	int *a_p;
	int *b_p;
	a_p = (int *) a;
	b_p = (int *) b;

	if( *a_p  == *b_p ) return 0;
	else if ( *a_p < *b_p  ) return -1;
	else return -1;
}

int cmp_str ( const void *a, const void *b){
	return strcmp( (char *) a, (char * ) b);
}


int SearchArray(Array *self, void *data , int (*cmp) (const void *a, const void *b)){
	int i;
	int *a = self -> front;

	for(i=0 ; i < self -> length; i++){
		if( 0== 
		cmp( (char *) (self -> front) +  (self->element_size) * i, data)) 
			return i;
	}
	return FAIL;

} // index 반환 

void TraverseArray(Array *self, void (*traverse) (void * data)){
	int i;
	int element_size = self -> element_size; 
//	printf("\n길이 : %d\n",  self -> length);
	for(i=0; i< self ->length; i++){
	   // 
		traverse((char*)self->front + i*element_size);
		//
	}
	printf("\n");
}
/*
void print_int(void * x){
	printf("%3d ",*(int *)x);
}
void print_str(void * x){
	printf("%-10s " ,x);
}*/
void Traverse_Int(Array *self){
	int i;
	int *  a= self -> front ;
	for(i=0; i< self ->length; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void Traverse_Str(Array *self){
	int element_size= self -> element_size;
	int len = self-> length;	
	int i;
	for(i=0; i< len; i++){
		printf("%-10s ",(char*)self->front +i* element_size);
	}
	//printf("\n");
}
void* GetData(Array *self, int index , void *data){ 
	if(index >=0 && index < self -> length ){
		memcpy(data,(((char *)(self -> front ) + index* (self -> element_size))),self-> element_size); 
		return data ;
	}
	else{
		return NULL ;
	}
}

void SetData(Array *self, int index, void * data){
	if(index >=0 && index < self -> length ){
		 memcpy( (char*) (self -> front ) + (index) * (self-> element_size), data, self->element_size);
		 return ;
	}
	else
		return ;
}

int GetCapacity(Array *self){ 
	return self->capacity;
}

int GetLength(Array* self){
	return self-> length;
}
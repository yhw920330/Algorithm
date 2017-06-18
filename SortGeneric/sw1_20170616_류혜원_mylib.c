#include"sw1_20170616_류혜원_mylib.h"
#define DUPLICATED 1
#define UNIQUE 0

void getProductInfo(Product * p){
	int i;
	char tp[40];
	for(i=0 ; i<ProductTotalNumber; i++){
		//checkDuplication
		printf("--품목 정보 입력(%d번째)--\n",i+1);
		printf("품목명 : ");
		fflush(stdin);
		gets(tp);
		if(strlen(tp)>20){
			printf("품목의 최대 길이는 20글자 입니다(재입력)\n\n");
			i--;
			continue;
		}
		if(DUPLICATED == checkDuplication(p,i,tp)){
			printf("Error : 이미 존재하는 품목명입니다(재입력)\n\n");
			i--;
			continue;
		}
		strcpy(p[i].name,tp);
		printf("단가  : ");
		scanf("%lf",&p[i].cost);

		//initialize 
		p[i].amount=0;
		p[i].total_price = 0;
		//
	}
}

int checkDuplication(const Product *p, int max, const char name[]){
	int i;
	int result=UNIQUE;
	for(i=0; i<=max; i++){
		if(!strcmp(p[i].name, name)){
			result =DUPLICATED;
			i=max;
		}
	}
	return result;
}

void PrintProduct(Product *p, int idx){
	printf("[%d ]품목명: %-20s\t 단가:%10.3lf\t 수량:%5d\t 판매금액: %.3lf\n",idx+1, p[idx].name,p[idx].cost,p[idx].amount,p[idx].total_price);
}
void PrintAllProducts(Product *p){
	int i=0;
	for(i=0; i<ProductTotalNumber; i++){
		PrintProduct(p,i);
	}
}


void getSaleInfo(Product *p){

	char tp_name[20];
	int tp_amount;
	int position;
	printf("\n--판매정보 입력---\n");
	while(1){
		fflush(stdin);
		//품목명 입력
		printf("품목명 입력 : ");
		gets(tp_name);
		if(strcmp(tp_name,"end")==0){
			break;
		}
		position=searchProductByName(p,tp_name);
		if(position ==-1){
			printf("Error : No product Under '%s'\n", tp_name);
			continue;
		}
		
		//수량 입력
		printf("수량 입력 : ");
		scanf("%d", &tp_amount);
		
		//수량 정보 반영
		updateProductInfo(p,position,tp_amount);
	
	}

}

int searchProductByName(Product *p, char name[20]){
	int position =-1;
	int i;
	for(i=0; i<ProductTotalNumber; i++)
	{
		if(strcmp(p[i].name, name) ==0){
			position=i;
			i=ProductTotalNumber;
		}
	}
	return position;

}

void updateProductInfo(Product *p, int index, int amount){
	p[index].amount += amount;
	p[index].total_price+= p[index].cost*amount;
}



void mySort(void * arr, int element_cnt, int element_size, int (*comp_func) (const void * cmp1, const void *cmp2)){
	int i,j,k;
	int loopMax = element_cnt -1;
	int innerLoop;
	void * tp = malloc(element_size);

	
	for(i=0; i< loopMax ; i++){
		k=0;
		innerLoop = loopMax -i;
		for(j=0; j < innerLoop; j++){
			if( comp_func( (char *)arr + j*element_size, (char *) arr+ (j+1)*element_size)   >0 ) {
				memcpy(tp, (char *) arr +  j * element_size, element_size);
				memcpy((char *) arr +  j * element_size ,	(char *) arr +  (j +1) * element_size, element_size); 
				memcpy((char *) arr +  (j+1) * element_size, tp, element_size);
			}
		}
	}
}


int cmp_ProductName(const void * p1, const void *p2){
	return strcmp( ((const Product *) p1)->name ,  ((const Product *) p2)->name ) ;
}



int cmp_ProductTotalPrice (const void * p1, const void * p2){
	if( ((*(Product *)p1).total_price - (*(Product *)p2).total_price) >  0 ) return -1;	
	else if ( ((*(Product *)p1).total_price - (*(Product *)p2).total_price) == 0 ) return 0;
	else return 1;
}


void PrintAllProductOrderedByName(Product *p){
	
	printf("-------------판매명순-------------\n");
	mySort(p,ProductTotalNumber, sizeof(Product),cmp_ProductName);
	PrintAllProducts(p);
}

void PrintAllProductOrderedByTotalPrice(Product *p){
	
	printf("-------------판매액순-------------\n");
	mySort(p,ProductTotalNumber, sizeof(Product), cmp_ProductTotalPrice);
	PrintAllProducts(p);
}
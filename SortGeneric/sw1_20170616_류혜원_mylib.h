#ifndef  _mylib_h
#define _mylib_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ProductTotalNumber 10
typedef struct _Product{
	char name[20];
	double cost;
	int amount;
	double total_price;
}Product;


void getProductInfo(Product *);
int checkDuplication(const Product *p, int max, const char name[]);

void PrintProduct(Product *p, int idx);
void PrintAllProducts(Product *p);
void getSaleInfo(Product *p);
int searchProductByName(Product *p, char name[20]);
void updateProductInfo(Product *p, int index, int amount);


void mySort(void * arr, int element_cnt, int element_size, int (*comp_func) (const void * cmp1, const void *cmp2));
int cmp_str(const void * str1, const void *str2);
int cmp_double (const void * double1, const void * double2);

int cmp_ProductName(const void * p1, const void *p2);
int cmp_ProductTotalPrice (const void * p1, const void * p2);

void PrintAllProductOrderedByName(Product *p);
void PrintAllProductOrderedByTotalPrice(Product *p);

#endif
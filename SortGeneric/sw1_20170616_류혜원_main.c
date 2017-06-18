#include"sw1_20170616_류혜원_mylib.h"
int main(){

	Product p[ProductTotalNumber];

	getProductInfo(p);
	PrintAllProducts(p);
	
	getSaleInfo(p);

	printf("품명순 정렬\n");
	PrintAllProductOrderedByName(p);
		PrintAllProductOrderedByTotalPrice(p);
	
	return 0;
}
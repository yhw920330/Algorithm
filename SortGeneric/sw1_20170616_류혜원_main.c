#include"sw1_20170616_������_mylib.h"
int main(){

	Product p[ProductTotalNumber];

	getProductInfo(p);
	PrintAllProducts(p);
	
	getSaleInfo(p);

	printf("ǰ��� ����\n");
	PrintAllProductOrderedByName(p);
		PrintAllProductOrderedByTotalPrice(p);
	
	return 0;
}
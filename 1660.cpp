#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int candidate[122];
int tab[300001];
int main() {

	int a;
	scanf("%d", &a);
	int i,j;
	int bound;
	//ÃÊ±âÈ­
	for (i = 1; i < 122; i++) {
		candidate[i] = i*(i + 1)*(i + 2) / 6;
	//		printf("%d : %d\n", i, candidate[i]);
		if (candidate[i] > a) {
			bound = i - 1;
			break;
		}
	}
//	printf("bound : %d\n", bound);
	tab[0] = 0;
	tab[1] = 1;

	for (i = 2; i <= a; i++) {
		int min = INT_MAX;
		for (j = 1; j <= bound; j++) {
			if (i - candidate[j] >= 0) {
				if (min > tab[i - candidate[j]] + 1) {
					min = tab[i - candidate[j]] + 1;
				}
			}
		}
		tab[i] = min;
	}
	//for (i = 0; i <= a; i++)
	//	printf("%d : %d\n", i, tab[i]);
	printf("%d\n", tab[a]);


}
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
bool compare(int a, int b) {
	if (a >=10 && b >=10) {  //a,b 두자리
		if (a / 10 == b / 10) {
			return a % 10 > b % 10;
		}
		return (a / 10 > b / 10);
	}
	else if (a >=10) { //a 두자리 b 한자리 
		return ( a  > b*11);
	}
	else if (b >= 10) {
		return (a*11 > b);
	}
	else
		return a > b;
}



int compare2(int a, int b) {
	if (a / 10 > b / 10) {
		return -1;
	}
	else if (a / 10 < b / 10) {
		return 1;
	}
	else { // == 일경우
		if (a % 10 > b % 10) {
			return -1;
		}
		else {
			return 1;
		}

	}
}


int main() {
	int input[10];
	int size = 0;
	char max[20];
	char min[20];
	unsigned long long a;
	unsigned long long b;
	
	int i;

	char in[30];
	
	scanf("%[^\n]", in);
	char *tp;
	tp = strtok(in, " ");
	sscanf(tp, "%d", &input[0]);
	for (i = 1,size=1 ; i < 10; i++,size++) {
		tp = strtok(NULL, " ");
		if (tp == NULL)
		{
			break;
		}
		sscanf(tp, "%d", &input[i]);
		
	}

	//max값 구하기
	sort(input, input+size,compare);
	for (i = 0; i < size; i++) {
		printf("%d : %d\n", i, input[i]);
	}

	strcpy(max,"");
	strcpy(min, "");
	for (i = 0; i < size; i++) {
		sprintf(max, "%s%d", max, input[i]);
		sprintf(min, "%s%d", min, input[size - 1 - i]);
	}
	printf("%s", max);
	printf("%s\n", min);
	sscanf(max, "%lld", &a);

	sscanf(min, "%lld", &b);
	printf("%lld\n", a + b);
	return 0;
}
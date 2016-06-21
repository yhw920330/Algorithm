#include<iostream>
using namespace std;
int p[40][2] = { 0, };
int t, n, t1 = 0, t2 = 0;
void fib(int n);
int main()
{
	cin >> t; //input 입력받기
	while (t--) {
		cin >> n;
		fib(n);
		cout << p[n][0]<<" " <<p[n][1]<< endl;
	}
}
void fib(int n) {

	if (n == 0) {
		p[n][0] = 1;
		p[n][1] = 0;
	}
	else if (n == 1)
	{
		p[n][0] = 0;
		p[n][1] = 1;
	}
	else {
		int s1=0, s2=0;
		if ( (p[n - 1][0]+p[n-1][1]) == 0) {
			fib(n - 1);
		}
		if ((p[n - 2][0]+p[n-2][1]) == 0) {
			fib(n - 2);
		}
		p[n][0] = p[n - 1][0] + p[n - 2][0];
		p[n][1] = p[n - 1][1] + p[n - 2][1];

	}
}
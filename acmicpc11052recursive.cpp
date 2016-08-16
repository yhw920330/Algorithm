#include<stdio.h>
#include<stdlib.h>
int max_until(int);
int *p;
int * dp;
int main()
{
	int N;
	scanf("%d", &N);
	int i;
	p = (int *)malloc(sizeof(int)*(N + 1));
	dp = (int *)malloc(sizeof(int)*(N + 1));

	for (i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
		dp[i] = 0;
	}

	printf("%d",max_until(N));
}

int max_until(int n) {

	if (dp[n] != 0) return dp[n];

	if (n == 1) {
		dp[1] = p[1];
		return dp[n];
	}

	int max = p[n];
	for (int j = 1; j <= n / 2; j++)
	{
		int pre = max_until(j);
		int post = max_until(n - j);
		if (max < (pre+post))
			{
				max = pre+post;
			}
	}
	dp[n] = max;
	return dp[n];
}
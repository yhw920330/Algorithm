/*#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N;
	int *p;
	int *dp;
	scanf("%d",&N);
	int i;
	p = (int *)malloc(sizeof(int)*(N + 1));
	dp = (int *)malloc(sizeof(int)*(N + 1));

	for (i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
		dp[i] = 0;
	}

	dp[1] = p[1];
	for (i = 2; i <= N; i++) {
		int max = p[i];
		for (int j = 1; j <= i / 2; j++)
		{
			if (max < (dp[j] + dp[i - j]))
			{
				max = dp[j] + dp[i - j];
			}
		}
		dp[i] = max;
	}
	printf("%d\n", dp[N]);
}

*/
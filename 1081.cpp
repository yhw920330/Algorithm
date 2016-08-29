#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long nine[16];
long long f(long long n) {
	if (n < 10)
		return (n)*(n + 1) / 2;

	int digit = log10(n);
	long long power = ceil(pow(10, digit));

	int msd = n / power;
	return msd*nine[digit] + (msd*(msd - 1)/ 2)*power + msd*(1 + n%power) + f(n%power);
}

int main() {
	long long a, b;
	int t;
//	scanf("%d", &t);
//	while (t--)
//	{
		scanf("%lld %lld", &a, &b);
		int i;
		nine[0] = 0;
		nine[1] = 45;
		for (i = 2; i <= 15; i++) {
			nine[i] = nine[i - 1] * 10 + 45 * ceil(pow(10, i - 1));
			//	printf("nine[%d] : %lld\n", i,nine[i]);
		}
		
		printf("%lld\n", f(b) - f(a - 1));
//	}
return 0;
}
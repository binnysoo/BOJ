#include <stdio.h>
#include <math.h>

void divider(int N, int mul, int result[]) {
	int quotient, remainder, power, i, j;
	
	if (mul == 0) {
		for (i = 0; i <= N; i++) {
			result[i]++;
		}
		return 0;
	}
	else {
		power = pow(10, mul);
		quotient = N / power;
		remainder = N % power;

		result[quotient] += (remainder + 1);
		for (i = 0; i < quotient; i++) {
			result[i] += power;
		}
		for (i = 0; i < 10; i++) {
			for (j = mul - 1; j >= 0; j--) {
				result[i] += (quotient * pow(10, mul - 1));
			}
		}
	}

	divider(remainder, mul - 1, result);
}

int main() {
	int N, tmpN, mul = 0, i;
	int result[10] = { 0, };
	scanf("%d", &N);			  // N <= 1,000,000,000
	tmpN = N;
	while (tmpN >= 10) {		// N이 몇 자리 수인지 파악 (10^mul 자리 수)
		tmpN /= 10;
		mul++;
	}
	divider(N, mul, result);

	for (i = mul; i >= 0; i--) {
		result[0] -= pow(10, i);
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}

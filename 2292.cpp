#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	/*
	1 (1)
	2 ~ 7 (6)
	8 ~ 19 (12)
	20 ~ 37 (18)
	38 ~ 62 (24)
	*/

	int lv = 0;
	int tmp = 1;
	while (tmp < N) {
		lv++;
		tmp += 6 * lv;
	}

	printf("%d", lv + 1);

	return 0;
}
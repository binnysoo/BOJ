#include <iostream>
int good[80];

bool good_check(int idx) {
	int i, j, k;
	bool flag;
	for (i = 1; i <= idx; ++i) {
		for (j = 1; j <= (i + 1) / 2; ++j) {
			flag = true;
			for (k = 0; k < j; ++k) {
				if (good[i - k] != good[i - k - j]) {
					flag = false;
				}
			}
			if (flag) return false;
		}
	}
	return true;
}

void make(int N, int idx) {
	int i;

	if (idx >= N) {
		for (i = 0; i < N; i++)
			printf("%d", good[i]);
		exit(0);
	}

	for (i = 1; i <= 3; ++i) {
		if (i == good[idx - 1]) continue;
		good[idx] = i;
		if (good_check(idx)) {
			make(N, idx + 1);
		}
	}
}

int main() {
	int N, i;

	scanf("%d", &N);
	
	good[0] = 1;
	make(N, 1);

	return 0;
}
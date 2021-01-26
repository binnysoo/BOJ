#include <iostream>
#include <algorithm>

using namespace std;

int N;
int large = (1 << 10) - 1;
long long cnt[1024];

int hash_func(long long x) {
	int ret = 0;
	while (x > 0) {
		ret |= (1 << (x % 10));
		x /= 10;
		if (ret == large) break;
	}
	return ret;
}

int main() {
	int i, j;
	long long num = 0;
	long long x;

	fill(cnt, cnt + 1024, 0);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x;
		cnt[hash_func(x)]++;
	}

	for (i = 0; i < 1024; i++) {
		num += ((cnt[i] * (cnt[i] - 1)) / (long long)2); // nC2
		for (j = i + 1; j < 1024; j++) {
			if ((i & j) != 0) {
				num += (cnt[i] * cnt[j]);
			}
		}
	}

	cout << num;
	return 0;
}
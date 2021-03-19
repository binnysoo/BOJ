#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll		long long
#define MAX		10002
#define MOD		1000000007

using namespace std;

ll n, arr[MAX], dp[2][MAX];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {

	}
	dp[0][0] = arr[1] < 1 ? 1 : 0;
	if (arr[1] >= 1) {
		printf("0\n");
		return 0;
	}

	ll* prev = dp[0];
	ll* now = dp[1];

	for (int i = 2; i <= n; ++i) {
		memset(now, 0x00, sizeof(now));
		if (arr[i] == -1) {
			// 도둑이 훔쳐간 경우
			// 어떤 높이든 가능하다
			now[0] = prev[0] + prev[1];
			for (int j = 1; j <= 5000; ++j) {
				now[j] = prev[j - 1] + prev[j] + prev[j + 1];
			}
		}
		else if (arr[i] == 0) {
			now[0] = prev[0] + prev[1];
		}
		else {
			// 높이가 1 이상인 경우
			now[arr[i]] = prev[arr[i] - 1] + prev[arr[i]] + prev[arr[i + 1]];	
		}
		// update now and prev
		swap(now, prev);
	}
	printf("%lld", prev[0] % MOD);
}
#include <iostream>
#define MOD		1000000007
#define MAX_NUM	105
using namespace std;

int L, R, N;
long long dp[MAX_NUM][MAX_NUM][MAX_NUM]; // dp[n][l][r] = n개의 빌딩이 존재할 때 L = l, R = r인 경우의 수

int main() {
	cin >> N >> L >> R;

	dp[1][1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= L; ++j) {
			for (int k = 1; k <= R; ++k) {
				dp[i][j][k] = (dp[i - 1][j][k] * (i - 2) + dp[i - 1][j][k - 1] + dp[i - 1][j - 1][k]) % MOD;
			}
		}
	}

	cout << dp[N][L][R] % MOD;
	return 0;
}
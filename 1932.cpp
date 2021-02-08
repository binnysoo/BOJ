#include <iostream>
#define MAX		502

using namespace std;

int dp[MAX][MAX];
int arr[MAX][MAX];

int max2(int a, int b) {
	return a > b ? a : b;
}

int go(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = max2(go(i - 1,j - 1), go(i - 1, j)) + arr[i][j];
}

int main() {
	int n, i, j, max = 0, res;
	cin >> n;
	for (i = 0; i <= n + 1; ++i) {
		for (j = 0; j <= n + 1; ++j)
			dp[i][j] = -1;
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= i; ++j) {
			cin >> arr[i][j];
		}
	}

	for (i = 0; i <= n + 1; ++i) {
		dp[i][i+1] = dp[i][0] = dp[0][i] = 0;
	}
	dp[1][1] = arr[1][1];

	for (i = 1; i <= n; ++i) {
		res = go(n, i);
		if (max < res) max = res;
	}

	cout << max;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string A, B;
int** dp;

int max(int a, int b) {
	return a > b ? a : b;
}

int go(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;

	if (A[a - 1] == B[b - 1])
		dp[a][b] = go(a - 1, b - 1) + 1;
	else {
		dp[a][b] = max(go(a - 1, b), go(a, b - 1));
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, len_a, len_b;

	cin >> A;
	cin >> B;
	len_a = A.length(); len_b = B.length();
	dp = new int*[len_a + 1];
	for (i = 0; i <= len_a; i++) {
		dp[i] = new int[len_b + 1];
		if (i == 0)
			fill(dp[i], dp[i] + len_b + 1, 0);
		else {
			fill(dp[i], dp[i] + len_b + 1, -1);
			dp[i][0] = 0;
		}
	}

	go(len_a, len_b);
	cout << dp[len_a][len_b];
}
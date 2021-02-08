#include <iostream>
#include <vector>

#define MAX 1026

using namespace std;

int N, M;
int arr[MAX][MAX], dp[MAX][MAX];

int go(int i, int j) {
	if (dp[i][j] != 0) return dp[i][j];
	return dp[i][j] = go(i - 1, j) + go(i, j - 1) - go(i - 1, j - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j;
	int x1, y1, x2, y2;
	vector<int> ans;

	cin >> N >> M;

	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
	}

	// init
	for (i = 0; i <= N + 1; ++i) {
		for (j = 0; j <= N + 1; ++j) {
			dp[i][j] = 0;
		}
	}

	// top-down
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= N; ++j) {
			if (i == 1)
				dp[i][j] = dp[i][j - 1] + arr[i][j];
			else 
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (i = 0; i < M; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		ans.push_back(dp[x2][y2] -  dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
	}

	for (i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i != ans.size() - 1) cout << '\n';
	}

}
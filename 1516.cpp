#include <iostream>
#include <vector>
#define MAX 505

using namespace std;

vector<int> pre[MAX], post[MAX];
int time[MAX], dp[MAX];

int go(int x) {
	int i, max = 0, ret;
	if (dp[x] != -1) return dp[x];

	dp[x] = 0;

	for (i = 0; i < pre[x].size(); ++i) {
		ret = go(pre[x][i]);
		if (max < ret) max = ret;
	}
	return dp[x] = max + time[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, x, i, ans;

	cin >> N;
	for (i = 1; i <= N; ++i) {
		dp[i] = -1;
		cin >> time[i];
		while (1) {
			cin >> x;
			if (x == -1) break;
			pre[i].push_back(x);
			post[x].push_back(i);
		}
	}

	for (i = 1; i <= N; ++i) {
		if (pre[i].size() == 0)
			dp[i] = time[i];
	}

	for (i = 1; i <= N; ++i) {
		if (post[i].size() == 0)
			go(i);
	}

	for (i = 1; i <= N; ++i) {
		cout << dp[i] << '\n';
	}

	return 0;
}
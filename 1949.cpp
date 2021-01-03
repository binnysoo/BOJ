#include <iostream>
#include <vector>

#define TRUE 1
#define FALSE 0

using namespace std;

vector<int>* village;
int* resident;
int** dp;

int max(int a, int b) {
	return a > b ? a : b;
}

void add_edge(int u, int v) {
	village[u].push_back(v);
	village[v].push_back(u);
}

int go(int parent, int cur, int superb) {
	int i, next;

	if (dp[cur][superb] != -1) return dp[cur][superb];

	dp[cur][superb] = 0;

	if (superb == TRUE) {
		for (i = 0; i < village[cur].size(); i++) {
			next = village[cur][i];
			if (next == parent) continue;
			dp[cur][superb] += go(cur, next, FALSE);
		}
		dp[cur][superb] += resident[cur];
	}
	else {
		for (i = 0; i < village[cur].size(); i++) {
			next = village[cur][i];
			if (next == parent) continue;
			dp[cur][superb] += max(go(cur, next, FALSE), go(cur, next, TRUE));
		}
	}

	return dp[cur][superb];
}

int main() {
	int n, u, v, i;
	cin >> n;

	village = new vector<int>[n + 1];

	resident = new int[n + 1];
	resident[0] = 0;

	dp = new int* [n + 1];
	for (i = 0; i <= n; i++) {
		dp[i] = new int[2];
		dp[i][0] = dp[i][1] = -1;
	}

	for (i = 1; i <= n; i++) {
		cin >> resident[i];
	}

	for (i = 1; i < n; i++) {
		cin >> u >> v;
		add_edge(u, v);
	} add_edge(0, 1);

	for (i = 2; i <= n; i++) {
		if (village[i].size() == 1) {
			dp[i][TRUE] = resident[i]; dp[i][FALSE] = 0;
		}
	}

	cout << max(go(0, 1, TRUE), go(0, 1, FALSE));
}
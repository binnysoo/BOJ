#include <iostream>
#include <algorithm>

#define MAX		17
#define INF		987654321

using namespace std;

int N, START = 0;
int w[MAX][MAX], dp[MAX][1 << MAX];
int finish;

int min(int a, int b) {
	return a < b ? a : b;
}

int go(int now, int route) {
	int i;
	
	if (route == finish) return w[now][START] == 0 ? INF : w[now][START];
	if (dp[now][route] != INF) return dp[now][route];

	for (i = 0; i < N; ++i) {
		if (w[now][i] == 0) continue; // no route
		if ((route & (1 << i)) != 0) continue; // visited
		dp[now][route] = min(dp[now][route], go(i, route | (1 << i)) + w[now][i]);
	}
	return dp[now][route];
}

int main() {
	int i, j;
	cin >> N;
	finish = (1 << N) - 1;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cin >> w[i][j];
		}

		fill(dp[i], dp[i] + (1 << N), INF);
	}

	cout << go(START, 1 << START);

	return 0;
}
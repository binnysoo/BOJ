#include <iostream>
#include <cstring>
#include <stack>

#define MAX		1001

using namespace std;

int dp[MAX][MAX];
char X[MAX], Y[MAX];
stack<char> ans;

int max2(int a, int b) {
	return a > b ? a : b;
}

int go(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	
	dp[x][y] = 0;
	if (X[x - 1] == Y[y - 1]) {
		dp[x][y] = go(x - 1, y - 1) + 1;
	}
	else {
		dp[x][y] = max2(go(x - 1, y), go(x, y - 1));
	}


	return dp[x][y];
}

void make_result(int x, int y, int len) {
	if (len == 0) return;

	if (X[x-1] == Y[y-1]) {
		ans.push(X[x - 1]);
		make_result(x - 1, y - 1, len - 1);
	}
	else {
		if (dp[x - 1][y] >= dp[x][y - 1])
			make_result(x - 1, y, len);
		else
			make_result(x, y - 1, len);
	}

	return;
}

int main() {
	int i, j;
	int x_len, y_len, len;
	
	cin >> X >> Y;
	x_len = strlen(X);
	y_len = strlen(Y);

	for (i = 0; i <= x_len; ++i) {
		for (j = 0; j <= y_len; ++j) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else 
				dp[i][j] = -1;
		}
	}

	go(x_len, y_len);
	len = dp[x_len][y_len];
	cout << len << '\n';
	make_result(x_len, y_len, len);
	while (!ans.empty()) {
		cout << ans.top(); ans.pop();
	}
	
	return 0;
}
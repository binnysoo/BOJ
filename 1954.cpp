#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

#define TWO 0
#define THREE 1
#define MAX 1001
#define IMPOS -1000

using namespace std;

int dp[2][MAX], result[MAX];
int number[MAX];
stack<int> answer;
int N;

int max(int a, int b) {
	return a > b ? a : b;
}

int go(int idx, int group_num) {
	if (dp[group_num][idx] != -1)
		return dp[group_num][idx];

	dp[group_num][idx] = 0;
	
	if (group_num == TWO) {
		if (idx < 2) {
			return dp[group_num][idx] = IMPOS;
		}
		dp[group_num][idx] = max(go(idx-2, TWO), go(idx-2, THREE));
		
		if (dp[group_num][idx] != IMPOS) {
			if (number[idx] == number[idx - 1]) {
				dp[group_num][idx] += 2;
			}
		}
	}
	else if (group_num == THREE) {
		if (idx < 3) {
			return dp[group_num][idx] = IMPOS;
		}
		dp[group_num][idx] = max(go(idx - 3, TWO), go(idx - 3, THREE));

		if (dp[group_num][idx] != IMPOS) {
			if (number[idx] == number[idx - 1] && number[idx] == number[idx - 2]) {
				dp[group_num][idx] += 2;
			}
			else if (number[idx] == number[idx - 1] || number[idx] == number[idx - 2] || number[idx - 1] == number[idx - 2]) {
				dp[group_num][idx] += 1;
			}
		}
	}
	return dp[group_num][idx];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j;
	string tmp_number;

	cin >> tmp_number;
	N = tmp_number.length();

	fill(number, number + MAX, -1);
	for (i = 1; i <= N;i++) {
		number[i] = tmp_number[i-1] - '0';
	}

	// initialize
	for (i = 0; i < 2; i++) {
		fill(dp[i], dp[i] + MAX, -1);
	}
	dp[TWO][0] = dp[THREE][0] = 0;
	
	max(go(N, TWO), go(N, THREE));

	if (N % 2 == 0) {
		for (i = N; i > 0;) {
			if (dp[TWO][i] < dp[THREE][i]) {
				result[i] = 3;
				i -= 3;
			}
			else {
				result[i] = 2;
				i -= 2;
			}
		}
	}
	else {
		int flag = 0;
		for (i = N; i > 0;) {
			if (dp[TWO][i] < dp[THREE][i]) {
				result[i] = 3;
				flag = 1;
				i -= 3;
			}
			else if (dp[TWO][i] > dp[THREE][i]) {
				result[i] = 2;
				i -= 2;
			}
			else {
				if (flag == 0) {
					result[i] = 3;
					i -= 3;
					flag = 1;
				}
				else {
					result[i] = 2;
					i -= 2;
				}
			}
		}
	}

	int num;
	for (i = N; i > 0;) {
		num = result[i];
		for (j = 0; j < num; j++) {
			answer.push(number[i--]);
		}
		if (i != 0) answer.push(-1); // '-'
	}

	int tmp;
	while (!answer.empty()) {
		tmp = answer.top(); answer.pop();
		if (tmp == -1) cout << '-';
		else cout << tmp;
	}
 
}
#include <iostream>
using namespace std;
int main() {
	int n, max;
	int * arr, * dp;
	cin >> n;
	arr = new int[n];
	dp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 0;
	}
	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (max < dp[j])
					max = dp[j];
			}
		}
		dp[i] = max + arr[i];
	}

	max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i]) max = dp[i];
	}

	cout << max;
}
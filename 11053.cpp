#include <iostream>
using namespace std;
int main() {
	int* arr, * dp;
	int n, max = 0, result = 0;
	cin >> n;
	arr = new int[n];
	dp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (max < dp[j]) max = dp[j];
			}
		}
		dp[i] = max + 1;
	}
	for (int i = 0; i < n; i++) {
		if (result < dp[i]) result = dp[i];
	}
	cout << result;
	
}
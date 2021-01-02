#include <iostream>
using namespace std;
int main() {
	int n, max = 0;
	int* arr, * dp;
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
			if (arr[i] < arr[j]) {
				if (max < dp[j])
					max = dp[j];
			}
		}
		dp[i] = max + 1;
	}
	max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i]) max = dp[i];
	}
	cout << max;
}
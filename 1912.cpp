#include <iostream>
#include <math.h>
#define INFINITE 1000000
using namespace std;


int main() {
	int n, min = 1000000;
	int* dp;
	cin >> n;
	dp = new int[n + 1]; 
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = INFINITE;
	}
	for (int i = 1; i*i <= n; i++) {
		dp[i*i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		min = 1000000;
		for (int j = 1; j * j <= i; j++) {
			if (min > dp[i - j * j] + 1)
				min = dp[i - j * j] + 1;
		}
		dp[i] = min;
	}
	cout << dp[n];
}
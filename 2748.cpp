#include <iostream>

using namespace std;

long fib[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	fib[0] = 0; fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}
	cout << fib[n];
}
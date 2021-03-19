#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, B;
int A[5][5];

typedef int(*arr_ptr)[5];

arr_ptr mul(int n) {
	if (n == 1) {
		return A;
	} 

	int i, j, k;
	arr_ptr prev = mul(n - 1);
	int now[5][5];

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			now[i][j] = 0;
			for (k = 0; k < N; ++k) {
				now[i][j] += ((prev[i][k] * A[k][j]) % 1000);
			}
		}
	}

	return now;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j, k, tmp;

	cin >> N >> B;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}

	arr_ptr res = mul(B);
	int value[5][5];
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			value[i][j] = res[i][j] % 1000;
		}
		// cout ?!
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cout << value[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
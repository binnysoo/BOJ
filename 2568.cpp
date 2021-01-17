#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001

using namespace std;

int N, prv, last, len = 0;
int A[MAX], B[MAX];
vector<int> arr, lis;
vector<pair<int, int>> backtrace;
bool result[MAX] = { false, };

int main() {
	int i, a, b;
	fill(A, A + MAX, -1);
	fill(B, B + MAX, -1);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		A[a] = b;
		B[b] = a;
	}
	
	for (i = 0; i < MAX; i++) {
		if (A[i] != -1)
			arr.push_back(A[i]);
	}

	// arr 에서 LIS 찾기
	//fill(result.begin(), result.end(), false);
	lis.push_back(arr[0]); 
	backtrace.push_back(make_pair(++len, arr[0]));
	for (i = 1; i < N; i++) {
		if (lis.back() < arr[i]) {
			// extend
			lis.push_back(arr[i]);
			backtrace.push_back(make_pair(++len, arr[i]));
		}
		else {
			// replace
			auto pos = lower_bound(lis.begin(), lis.end(), arr[i]);
			*pos = arr[i];
			backtrace.push_back(make_pair(distance(lis.begin(), pos), arr[i]));
		}
	}


	cout << N - len << "\n";

	for (i = N - 1; i >= 0; i--) {
		if (len == backtrace[i].first) {
			result[backtrace[i].second] = true;
			len--;
		}
	}


	for (i = 0; i < N; i++) {
		if (!result[arr[i]] && B[arr[i]] != -1) {
			cout << B[arr[i]];
			if (i != MAX - 1) cout << "\n";
		}
	}
}
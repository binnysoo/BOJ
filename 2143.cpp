#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> A, B, A_sum, B_sum;
int t, n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, j, tmp, a, b;
	long long tmp_a, tmp_b, cnt_a, cnt_b;
	long long sum = 0, ans = 0;

	cin >> t;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		A.push_back(tmp);
		sum = 0;
		for (j = i; j >= 0; --j) {
			sum += A[j];
			A_sum.push_back(sum);
		}
	}
	sort(A_sum.begin(), A_sum.end());

	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> tmp;
		B.push_back(tmp);
		sum = 0;
		for (j = i; j >= 0; --j) {
			sum += B[j];
			B_sum.push_back(sum);
		}
	}
	sort(B_sum.begin(), B_sum.end(), greater<>());

	a = b = 0; 
	while (a < A_sum.size() && b < B_sum.size()) {
		sum = A_sum[a] + B_sum[b];
		if (sum == t) {
			tmp_a = A_sum[a]; tmp_b = B_sum[b];
			cnt_a = cnt_b = 0;
			while (a < A_sum.size() && A_sum[a] == tmp_a) {
				++cnt_a; ++a;
			}
			while (b < B_sum.size() && B_sum[b] == tmp_b) {
				++cnt_b; ++b;
			}
			ans += (cnt_a * cnt_b);
		}
		else if (sum > t) {
			++b;
		}
		else { // sum < t
			++a;
		}
	}

	cout << ans;
}

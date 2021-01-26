#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, i, tmp, sum = 0, left = 0, right = 0, ans = 0;
	vector<int> num;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}

	while (left <= right) {
		if (sum == M) {
			++ans;
			sum -= num[left++];
		}
		else if (sum > M) {
			sum -= num[left++];
		}
		else if (sum < M) {
			if (right > N - 1) break;
			sum += num[right++];
		}
	}
	cout << ans;
}
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N, S, len = MAX;
vector<int> nums;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, tmp, sum, left, right, res = MAX;
	cin >> N >> S;

	for (i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}

	sum = left = right = 0;
	while (left <= right) {
		if (sum < S) {
			if (right > N - 1) break;
			sum += nums[right++];
		}
		else {
			res = min(res, right - left);
			sum -= nums[left++];
		}
	}

	if (res == MAX)
		cout << 0;
	else
		cout << res;
}
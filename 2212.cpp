#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N, K, i;
	int sensor[10001];
	long long sum = 0;
	priority_queue<int> diff;

	cin >> N >> K;
	for (i = 0; i < N; ++i) {
		cin >> sensor[i];
	}

	sort(sensor, sensor + N);

	for (i = 1; i < N; ++i) {
		diff.push(sensor[i] - sensor[i-1]);
		sum += ((long long)sensor[i] - (long long)sensor[i - 1]);
	}

	for (i = 0; i < K - 1; ++i) {
		if (diff.empty()) break;
		sum -= (long long)diff.top();
		diff.pop();
	}

	cout << sum;
}
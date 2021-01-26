#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, i, tmp;
	vector<int> arr, numbers;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());

	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}

	int idx, l, r;
	for (i = 0; i < M; i++) {
		l = 0; r = N - 1;
		while (l <= r) {
			idx = (l + r) / 2;
			if (arr[idx] == numbers[i]) {
				cout << "1";
				break;
			}
			if (arr[idx] < numbers[i]) {
				l = idx + 1;
			}
			else if (arr[idx] > numbers[i]) {
				r = idx - 1;
			}
		}
		if (r < l) {
			cout << "0";
		}
		if (i != M - 1) cout << "\n";
	}
}
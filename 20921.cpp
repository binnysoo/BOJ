#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, K, cnt = 0;
vector<int> result;

void push_between(int val, int n) {
	int i;
	stack<int> tmp;
	for (i = 0; i < n; ++i) {
		tmp.push(result.back());
		result.pop_back();
	}
	result.push_back(val);
	while (!tmp.empty()) {
		result.push_back(tmp.top());
		tmp.pop();
	}
}

int main() {
	cin >> N >> K;

	result.push_back(1);
	for (int i = 2; i <= N; ++i) {
		if (cnt >= K) {
			result.push_back(i);
		}
		else if (result.size() <= K - cnt) {
			cnt += result.size();
			push_between(i, result.size());
		}
		else {
			push_between(i, K - cnt);
			cnt += (K - cnt);
		}
	}

	for (int x : result) {
		cout << x << ' ';
	}
}
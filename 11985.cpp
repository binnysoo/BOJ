#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<int> orange;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i;

	cin >> N >> M >> K;
	orange.reserve(N);

	for (i = 0; i < N; ++i) {
		cin >> orange[i];
	}

	return 0;
}
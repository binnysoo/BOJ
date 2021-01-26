#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> tree;

bool cut(int h) {
	int i; 
	long total = 0;
	for (i = 0; i < N; i++) {
		if (tree[i] > h)
			total += (tree[i] - h);
	}
	return (total >= M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, tmp, low = 0, high = 0, h;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> tmp;
		tree.push_back(tmp);
		if (high < tmp)
			high = tmp;
		if (tmp < low)
			low = tmp;
	}
	while (low <= high) {
		h = (low + high) / 2;
		if (cut(h))
			low = h + 1;
		else
			high = h - 1;
	}
	cout << low-1;
}
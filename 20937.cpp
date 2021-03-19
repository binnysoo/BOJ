#include <iostream>
#include <vector>
#include <algorithm>
#define MAX		50001
using namespace std;

int main() {
	int N, tmp, max = 0;
	int i, j;
	vector<int> c;
	int tower[MAX] = { 0, };
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> tmp;
		c.push_back(tmp);
	}
	sort(c.begin(), c.end(), greater<int>());
	for (i = 1; i < N; ++i) {
		if (c[i] == c[i - 1]) {
			++tower[c[i]];
			if (max < tower[c[i]]) {
				max = tower[c[i]];
			}
		}
	}
	cout << max + 1;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, H, i, tmp;
	vector<int> bottom, ceiling;

	cin >> N >> H;
	for (i = 0; i < N; ++i) {
		cin >> tmp;
		if (i % 2 == 0) bottom.push_back(tmp);
		else ceiling.push_back(tmp);
	}
}
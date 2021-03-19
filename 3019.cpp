#include <iostream>
#include <vector>

using namespace std;

int main() {
	int C, P, i, j, tmp, ans = 0, x, y;
	int fit[4];
	bool flag;
	vector<int> map, diff;

	cin >> C >> P;
	for (i = 0; i < C; ++i) {
		cin >> tmp;
		map.push_back(tmp);
		if (i == 0) diff.push_back(0);
		else diff.push_back(map[i] - map[i - 1]);
	}

	if (P == 1) {
		for (i = 0; i < C; ++i) {
			++ans;
		}
		fit[0] = fit[1] = fit[2] = fit[3] = 0;
		for (i = 0; i <= C - 4; ++i) {
			flag = true;
			for (j = i; j < i + 4; ++j) {
				if (fit[j - i] != diff[j]) {
					flag = false;
					break;
				}
			}
			if (flag) ++ans;
		}
	}
	else if (P == 2) {
		fit[0] = fit[1] = 0;
		for (i = 0; i <= C - 2; ++i) {
			flag = true;
			for (j = i; j < i + 2; ++j) {
				if (fit[j - i] != diff[j]) {
					flag = false;
					break;
				}
			}
			if (flag) ++ans;
		}
	}
	else if (P == 3) {
		fit[0] = fit[1] = 0;
		for (i = 0; i <= C - 2; ++i) {
			flag = true;
			for (j = i; j < i + 2; ++j) {
				if (fit[j - i] != diff[j]) {
					flag = false;
					break;
				}
			}
			if (flag) ++ans;
		}
	}

	cout << ans;
	return 0;
}
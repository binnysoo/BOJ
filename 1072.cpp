#include <iostream>
#include <vector>

using namespace std;

// https://www.acmicpc.net/board/view/39292

int main() {
	long long X, Y, Z, z;
	int cnt = 0, left, right, mid, i;
	cin >> X >> Y;

	Z = (Y * 100) / X;
	if (Z >= 99)
		cout << -1;
	else {
		left = 0; right = X;
		while (left <= right) {
			mid = (left + right) >> 1;
			z = ((Y + mid) * 100) / (X + mid);
			if (Z < z) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		cout << right + 1;
	}
}
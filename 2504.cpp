#include <iostream>
#include <stack>

using namespace std;

stack<char> s;
stack<int> val;

int main() {
	char c, pair;
	int ans = 0, x, tmp;

	while (~scanf("%c", &c)) {
		if (c == '\n') break;
		if (c == '(' || c == '[') {
			s.push(c);
			val.push(0);
		}
		else {
			if (s.empty()) {
				cout << 0;
				return 0;
			}
			pair = s.top(); s.pop();
			x = 0;
			while (!val.empty()) {
				tmp = val.top(); val.pop();
				if (tmp == 0) break;
				x += tmp;
			}
			x = x == 0 ? 1 : x;
			if (c == ')') {
				if (pair == '(') {
					val.push(x * 2);
				}
				else {
					cout << '0';
					return 0;
				}
			}
			else { // c == ']'
				if (pair == '[') {
					val.push(x * 3);
				}
				else {
					cout << '0';
					return 0;
				}
			}
		}
	}

	if (!s.empty()) {
		cout << 0;
		return 0;
	}

	while (!val.empty()) {
		ans += val.top(); val.pop();
	}

	cout << ans;
	return 0;
}
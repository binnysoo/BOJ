#include <iostream>
#include <string>
#include <cstring>
#include <queue>

#define D(x) x * 2 % 10000
#define S(x) x > 0 ? x - 1 : 9999
#define L(x) ((x % 1000) * 10) + (x / 1000)
#define R(x) (x / 10) + ((x % 10) * 1000)

int A, B;
bool made[10000] = { false, };

using namespace std;


string bfs() {
	int current, result;
	string history;
	queue<pair<int, string>> q;

	q.push(make_pair(A, ""));
	made[A] = true;

	while (!q.empty()) {

		current = q.front().first;
		history = q.front().second;
		q.pop();

		// D
		result = D(current);
		if (!made[result]) {
			made[result] = true;
			if (result == B)
				return history + "D";
			else q.push(make_pair(result, history + "D"));

		}

		// S
		result = S(current);
		if (!made[result]) {
			made[result] = true;
			if (result == B)
				return history + "S";
			else q.push(make_pair(result, history + "S"));
		}

		// L
		result = L(current);
		if (!made[result]) {
			made[result] = true;
			if (result == B)
				return history + "L";
			else q.push(make_pair(result, history + "L"));
		}

		// R
		result = R(current);
		if (!made[result]) {
			made[result] = true;
			if (result == B)
				return history + "R";
			else q.push(make_pair(result, history + "R"));
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A >> B;
		memset(made, false, sizeof(made));
		cout << bfs();
		if (i != n - 1) cout << endl;
	}
}
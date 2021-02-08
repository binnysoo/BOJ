#include <iostream>
#include <vector>
#include <algorithm>
#define MAX	505

using namespace std;

int N, M;
vector<int> *in, *out;
bool v[MAX];
int num[MAX] = { 0, };

void dfs_out(int root, int x) {
	v[x] = true;
	for (int y : out[x]) {
		if (!v[y]) {
			num[root]++;
			dfs_out(root, y);
		}
	}
	return;
}


void dfs_in(int root, int x) {
	v[x] = true;
	for (int y : in[x]) {
		if (!v[y]) {
			num[root]++;
			dfs_in(root, y);
		}
	}
	return;
}

int main() {
	int i, a, b, ans = 0;
	cin >> N >> M;

	in = new vector<int>[N + 1];
	out = new vector<int>[N + 1];

	for (i = 0; i < M; ++i) {
		cin >> a >> b;
		out[a].push_back(b);
		in[b].push_back(a);
	}

	for (i = 1; i <= N; ++i) {
		fill(v, v + N + 1, false);
		dfs_in(i, i);
		dfs_out(i, i);
		if (num[i] == N - 1) ans++;
	}
	cout << ans;

	return 0;
}
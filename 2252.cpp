#include <iostream>
#include <vector>
#define MAX 32005

using namespace std;

int N, M;
vector<int> *out, *in;
vector<int> ans;
bool v[MAX];

void dfs(int x) {
	v[x] = true;
	for (int y : out[x]) {
		if (!v[y]) {
			dfs(y);
		}
	}
	ans.push_back(x);
	return;
}

int main() {
	int i, a, b;
	cin >> N >> M;

	out = new vector<int>[N + 1];
	in = new vector<int>[N + 1];

	for (i = 1; i <= N; ++i) {
		v[i] = false;
	}

	for (i = 0; i < M; ++i) {
		cin >> a >> b;
		out[a].push_back(b);
		in[b].push_back(a);
	}

	for (i = 1; i <= N; ++i) {
		if (in[i].size() == 0) {
			dfs(i);
		}
	}

	for (i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
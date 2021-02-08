#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int par[1005];

int find(int a) {
	if (par[a] == a) return par[a];
	return par[a] = find(par[a]);
}

void merge(int a, int b) {
	int aa = find(a);
	int bb = find(b);
	par[aa] = par[bb];
}

int main() {
	int N, M, i, a, b, c, cost = 0, num = 0;
	typedef pair<int, pair<int, int>> piii; // cost, node
	priority_queue<piii> g;
	piii cur;

	cin >> N >> M;

	for (i = 1; i <= N; ++i) {
		par[i] = i;
	}

	for (i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		g.push(make_pair(-c, make_pair(a, b)));
	}

	while (1) {
		if (num >= N - 1) break;
		cur = g.top(); g.pop();
		a = cur.second.first;
		b = cur.second.second;
		if (find(a) != find(b)) {
			merge(a, b);
			cost -= cur.first;
			++num;
		}
	}

	cout << cost;

	return 0;
}
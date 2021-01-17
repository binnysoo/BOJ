#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INFINITE 100000000

using namespace std;

int N, M, X;
vector<pair<int, int>>* g; // (node, weight)
int* go;
int* back;
bool* visited;

int min(int a, int b) {
	return a < b ? a : b;
}

void dfs(int start, int from, int to, int time, bool* v) {
	int next;

	v[from] = true;
	if (from == to) {
		if (time < go[start])
			go[start] = time;
		return;
	}

	for (int i = 0; i < g[from].size(); i++) {
		next = g[from][i].first;
		if (!v[next]) {
			//v[next] = true;
			dfs(start, next, to, time + g[from][i].second, v);
		}
	}
	return;
}

void dfs2(int start, int from, int to, int time, bool* v) {
	int next;

	v[from] = true;
	if (from == to) {
		if (time < back[start])
			back[start] = time;
		return;
	}

	for (int i = 0; i < g[from].size(); i++) {
		next = g[from][i].first;
		if (!v[next]) {
			dfs2(start, next, to, time + g[from][i].second, v);
		}
	}
	return;
}

int main() {
	int u, v, w, i, tmp, max = 0;

	cin >> N >> M >> X;
	g = new vector<pair<int, int>>[N + 1];
	go = new int[N + 1]; 
	fill(go, go + N + 1, INFINITE);
	back = new int[N + 1]; 
	fill(back, back + N + 1, INFINITE);
	visited = new bool[N + 1];
	for (i = 0; i < M; i++) {
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w)); // w: time cost from u to v
	}

	for (i = 1; i <= N; i++) {
		fill(visited, visited + N + 1, false);
		dfs(i, i, X, 0, visited);
	}

	for (i = 1; i <= N; i++) {
		fill(visited, visited + N + 1, false);
		dfs2(i, X, i, 0, visited);
	}

	for (i = 1; i <= N; i++) {
		if (max < go[i] + back[i]) max = go[i] + back[i];
	}

	cout << max;

	return 0;
}
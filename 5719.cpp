#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_V	505
#define INF		10000005
using namespace std;

typedef struct _edge {
	int u;
	int v;
	int w;
} edge;
typedef pair<int, int> pii;

int N, M, S, D;
int dist[MAX_V], path[MAX_V];
//vector<pii> adj[MAX_V];
int adj[MAX_V][MAX_V];
priority_queue<pii> pq;

void init(int num, int src) {
	int i;
	while (!pq.empty()) pq.pop();

	for (i = 0; i < num; ++i) {
		path[i] = INF;
		dist[i] = INF;
	}
	dist[src] = 0;
}

void delete_path() {
	int cur = D, prev = path[D];
	while (cur != S) {
		adj[prev][cur] = 0;
		cur = prev;
		prev = path[prev];
	}
}

void dijkstra() {
	int a, b;
	pii next;

	pq.push(make_pair(-dist[S], S));
	while (!pq.empty()) {
		next = pq.top(); pq.pop();
		a = next.second;
		for (b = 0; b < N; ++b) {
			if (adj[a][b] == 0) continue;
			if (dist[a] + adj[a][b] < dist[b]) {
				dist[b] = dist[a] + adj[a][b];
				pq.push(make_pair(dist[b], b));
				path[b] = a;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j, u, v, w, min;
	vector<int> ans;

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> D;
		
		init(N, S);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) 
				adj[i][j] = 0;
		}

		for (i = 0; i < M; ++i) {
			cin >> u >> v >> w;
			adj[u][v] = w;
		}
		dijkstra();
		min = dist[D];
		while (dist[D] == min && dist[D] != INF) {
			delete_path();
			init(N, S);
			dijkstra();
		}
		if (dist[D] == INF) ans.push_back(-1);
		else				ans.push_back(dist[D]);
	}

	for (i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i != ans.size() - 1) cout << '\n';
	}

	return 0;
}
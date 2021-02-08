#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_V	10005
#define MAX_E	100005

using namespace std;

int V, E, num = 0;
vector<int> adj[MAX_V];
int visit[MAX_V];
bool cut[MAX_V];

int min2(int a, int b) {
	return a < b ? a : b;
}

int dfs_line(int now, int prev) {
	// now 는 현위치, prev는 전 위치(부모)
	visit[now] = ++num;
	int ret = visit[now];

	for (int next : adj[now]) {
		if (next == prev) continue;
		if (visit[next]){
			ret = min2(ret, visit[now]);
			continue;
		}
		int min = dfs_line(next, now);
		if (min > visit[now]) {
			// 단절선
		}
		ret = min2(ret, min);
	}
	return ret;
}

int dfs(int now, bool isRoot) {
	int ret, min, child_cnt = 0;
	visit[now] = ++num;
	ret = visit[now];
	for (int next : adj[now]) {
		if (visit[next]) {
			ret = min2(ret, visit[next]);
			continue;
		}
		child_cnt++;
		// child node가 가져오는 값 (min값)
		min = dfs(next, false);
		// next 가 부모일 수도 있기 때문에 > 가 아니라 >=
		if (!isRoot && min >= visit[now]) {
			// 단절점
			cut[now] = true;
		}
		ret = min2(ret, min);
	}
	if (isRoot && child_cnt > 1) {
		// 단절점
		cut[now] = true;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, a, b, cnt = 0;

	cin >> V >> E;
	for (i = 0; i < E; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a); // undirected
	}

	for (i = 1; i <= V; ++i) {
		if (!visit[i])
			dfs(i, true);
	}
	
	for (i = 1; i <= V; ++i) {
		if (cut[i]) cnt++;
	}
	cout << cnt << '\n';
	for (i = 1; i <= V; ++i) {
		if (cut[i])
			cout << i << ' ';
	}
 	return 0;
}
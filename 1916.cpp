#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000000

using namespace std;

int N, M;
vector<pair<int, int>>* g;
auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.second > right.second; };
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
int* d;

int main() {
	int i, a, b, cost, next;
	cin >> N;
	cin >> M;
	g = new vector<pair<int, int >>[N + 1];
	d = new int[N + 1]; fill(d, d + (N + 1), INF);
	
	for (i = 0; i < M; i++) {
		cin >> a >> b >> cost;
		g[a].push_back(make_pair(b, cost));
	}
	cin >> a >> b;
	d[a] = 0;
	pq.push(make_pair(a, 0)); 

	while (!pq.empty()) {
		a = pq.top().first; pq.pop();
		for (i = 0; i < g[a].size(); i++) {
			next = g[a][i].first; cost = g[a][i].second;
			if (d[a] + cost < d[next]) {
				d[next] = d[a] + cost;
				pq.push(make_pair(next, d[next]));
			}
		}
	}
	cout << d[b];
}
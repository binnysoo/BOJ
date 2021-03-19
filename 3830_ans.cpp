#include <iostream>
#include <vector>
#define MAX 100005
#define INF 1000001

using namespace std;

int par[MAX], dist[MAX], child[MAX];
int n, m, a, b, w;
char code;

int find(int a) {
	if (par[a] == a) return par[a];
	int aa = find(par[a]);
	dist[a] += dist[par[a]];
	return par[a] = aa;
}

void merge(int a, int b, int w) {
	int aa = find(a);
	int bb = find(b);

	if (child[aa] > child[bb]) {
		par[bb] = par[aa];
		dist[bb] += (dist[a] + w - dist[b]);
		child[aa] += child[bb];
		child[bb] = 1;
	}
	else {
		par[aa] = par[bb];
		dist[aa] += (dist[b] + w - dist[a]);
		child[bb] += child[aa];
		child[aa] = 1;
	}
}

int main() {
	int i;
	vector<int> ans;


	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (i = 1; i <= n; ++i) {
			par[i] = i;
			dist[i] = 0;
			child[i] = 1;
		}

		for (int i = 0; i < m; ++i) {
			cin >> code;
			if (code == '!') {
				cin >> a >> b >> w;
				merge(a, b, w);
			}
			else {
				cin >> a >> b;
				if (find(a) == find(b)) {
					ans.push_back(dist[b] - dist[a]);
				}
				else {
					ans.push_back(INF);
				}
			}
		}
	}


	for (i = 0; i < ans.size(); ++i) {
		if (ans[i] == INF)
			cout << "UNKNOWN\n";
		else 
			cout << ans[i];

		if (i != ans.size() - 1) cout << "\n";
	}

	return 0;
}
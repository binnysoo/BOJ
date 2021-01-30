#include <iostream>
#include <vector>

#define MAX_SZ	1001
#define INF		1000000

using namespace std;

int N, M;
vector<int> K;
int weight[MAX_SZ][MAX_SZ], dist[MAX_SZ];
bool visited[MAX_SZ];

typedef pair<int, int> pii;
pii selected[MAX_SZ];

int choose() {
	int i, min = INF, pos = -1;

	for (i = 1; i <= N; ++i) {
		if (!visited[i] && dist[i] < min) {
			min = dist[i];
			pos = i;
		}
	}

	return pos;
}

void dijkstra() {
	int i, a, b, min;
	pii path;
	while((a = choose()) != -1) {
		for (b = 1; b <= N; ++b) {
			if (weight[a][b] != INF && dist[a] + weight[a][b] < dist[b]) {
				dist[b] = dist[a] + weight[a][b];
				selected[b] = { a, b };
			}
		}
		visited[a] = true;
	}
}

int main() {
	int i, j, a, b, c;

	cin >> N >> M;
	
	// init
	for (i = 0; i <= N; ++i) {
		for (j = 0; j <= N; ++j) weight[i][j] = INF;
		dist[i] = INF;
		visited[i] = false;
		selected[i] = { -1, -1 };
	}

	for (i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		weight[a][b] = weight[b][a] = c;
	}

	dist[1] = 0;
	dijkstra();

	for (i = 1; i <= N; ++i) {
		if (selected[i] != make_pair(-1, -1)) 
			K.push_back(i);
	}

	cout << K.size() << "\n";

	for (i = 0; i < K.size(); ++i) {
		cout << selected[K[i]].first << ' ' << selected[K[i]].second << '\n';
	}

	return 0;
}
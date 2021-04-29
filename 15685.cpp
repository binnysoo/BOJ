#include <iostream>
#include <queue>
#define MAX_SZ	101
using namespace std;

typedef pair<int, int> pii;

int N;
bool grid[MAX_SZ][MAX_SZ];
queue<pii> q, tmp1, tmp2;

int dy[4] = { 0,-1,0,1 }; // 오 위 왼 아
int dx[4] = { 1,0,-1,0 };

int main() {
	int x, y, d, g;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y >> d >> g;

		// dragon curve
		int gen = 0;
		while (!q.empty()) q.pop();
		q.push(make_pair(y, x));
		q.push(make_pair(y + dy[d], x + dx[d])); // move to the corresponding direction

		grid[y][x] = true;
		grid[y + dy[d]][x + dx[d]] = true;
		
		pii center = make_pair(y + dy[d], x + dx[d]);
		pii next_center;

		while (gen < g) {
			while (!q.empty()) {
				pii cur = q.front(); q.pop();
				int i = cur.first;
				int j = cur.second;
				tmp1.push(cur);

				if (center.first == i && center.second == j) continue;

				// roatate
				int newi = center.first - (center.second - j); 
				int newj = center.second + (center.first - i);

				if (newi >= 0 && newi <= 100 && newj >= 0 && newj <= 100)
					grid[newi][newj] = true;
				
				if (i == y && j == x) {
					next_center = make_pair(newi, newj);
				}

				tmp2.push(make_pair(newi, newj));
			}
			while (!tmp1.empty()) {
				q.push(tmp1.front());
				tmp1.pop();
			}
			while (!tmp2.empty()) {
				q.push(tmp2.front());
				tmp2.pop();
			}
			gen++;
			center = next_center;
		}
	}

	// count
	int ans = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1])
				ans++;
		}
	}

	cout << ans;



	return 0;
}

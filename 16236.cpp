#include <iostream>
#include <queue>
#define MAX_SZ	20
using namespace std;

int N, M, shark = 2;
int map[MAX_SZ][MAX_SZ];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

typedef pair<int, int> pii;
pii START;
queue<pii> q, fish;

// BFS 
// 먹을 물고기 순서 찾기
void bfs() {
	int x, y, nx, ny;
	pii cur;
	q.push(START);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			x = cur.first + dx[i];
			y = cur.second + dy[i];

			// 이동할 수 없는 경우
			if (x < 0 || y < 0 || x > N - 1 || y > N - 1) 
				continue;
			if (shark < map[x][y])
				continue;

			// 먹을 수 있는 물고기가 있는 경우
			
			
		}
	}
}

int main() {
	int time = 0;
	int i, j;
	cin >> N;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				START = { i, j };
			}
		}
	}

	bfs();

	// 시간 계산


	cout << time;

	return 0;
}
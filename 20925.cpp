#include <iostream>
#include <vector>
#include <queue>
#define MAX		205

using namespace std;

int N, T;
int enter[MAX], gain[MAX];
int dist[MAX][MAX];
typedef pair<pair<int, int>, int> piii;
priority_queue<piii> ex; // ����, ����ġ, ����� ��ȣ


int main() {
	int i, j, c, e, time = 0, inc = 0, total = 0, START = 0;
	piii next;

	cin >> N >> T;
	for (i = 0; i < N; ++i) {
		cin >> enter[i] >> gain[i];
		if (enter[i] == 0) {
			if (gain[i] > gain[START])
				START = i;
		}
	}

	/*
	for (i = 0; i < N; ++i) {
		cin >> c >> e;
		ex.push(make_pair(make_pair(c, e), i));
	}*/

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			cin >> dist[i][j];
		}
	}


	while (time < T) {
		// �̵��� �� �ľ�
		// ���忡 �ʿ��� ����ġ Ȯ��


		// �̵��ϴ� ���

		// �̵����� �ʴ� ���
	}


	cout << total;

	return 0;
}
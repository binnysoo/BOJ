#include <iostream>
#include <queue>


using namespace std;

int N, K;
priority_queue<pair<int, int>> jewlery;
priority_queue<int> bag;

int main() {
	int i, m, v, c, left;
	pair<int, int> j;
	cin >> N >> K;
	for (i = 0; i < N; ++i) {
		cin >> m >> v;
		jewlery.push(make_pair(m, v));
	}
	for (i = 0; i < K; ++i) {
		cin >> c;
		bag.push(c);
	}
	for (i = 0; i < K; ++i) {
		// 가장 조금 담을 수 있는 가방부터
		left = bag.top(); bag.pop();
		j = jewlery.top(); jewlery.pop();
		if (j.first < left) {

		}
		
	}
}
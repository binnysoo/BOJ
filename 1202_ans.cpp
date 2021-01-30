#include <cstdio>
#include <queue>
#include <vector>

#define MAX_N		300000

using namespace std;

typedef pair<int, int> pii;

pii jems[MAX_N];
int bags[MAX_N];
priority_queue<int> pq;

int main() {
	int N, K, i, j;
	long long ans = 0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; ++i) {
		scanf("%d %d", &jems[i].first, &jems[i].second);
	}
	for (i = 0; i < K; ++i) {
		scanf("%d", &bags[i]);
	}
	// 무게가 가벼운 가방부터
	
	sort(jems, jems + N);
	sort(bags, bags + N);

	j = 0;
	for (i = 0; i < K; ++i) {
		while (j < N && jems[j].first <= bags[i]) {
			pq.push(jems[j++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	printf("%lld\n", ans);

	return 0;
}
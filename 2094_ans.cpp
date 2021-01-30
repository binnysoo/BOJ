#include <cstdio>

#define MAX_N		50000
#define SZ_TR		131072

int OFFSET, tree[SZ_TR];
int years[MAX_N], rains[MAX_N];

int max(int a, int b) { return a > b ? a : b; }

void init(int N) {
	int i;

	for (OFFSET = 0; OFFSET < N; OFFSET *= 2);
	for (i = 0; i < N; ++i) tree[OFFSET + i] = rains[i];
	for (i = OFFSET - 1; i > 0; --i) tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int query(int from, int to) {
	int res = 0;
	from += OFFSET, to += OFFSET;

	while (from <= to) {
		if (from % 2 == 1) res = max(res, tree[from++]);
		if (to % 2 == 1) res = max(res, tree[to--]);
		from /= 2, to /= 2;
	}
	return res;
}

int main() {
	int N, i;
	int Q, Y, X, yIdx, xIdx;
	int low, high, mid;

	scanf("%d", &N);
	for (i = 0; i < N; ++i)scanf("%d %d", years + i, rains + i);
	
	init(N);

	scanf("%d", &Q);
	while (Q--) {
		scanf("%d %d", &Y, &X);
		low = 0, high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] >= Y) high = mid - 1;
			else low = mid + 1;
		}
		yIdx = high + 1;

		low = 0, high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] < X) low = mid + 1;
			else high = mid - 1;
		}
		xIdx = low - 1;

		if (years[yIdx] != Y && years[xIdx != X])
			printf("maybe\n");
		else if (years[xIdx] != X && years[yIdx] == Y) {
			if (query(Y + 1, X) < rains[yIdx]) printf("maybe\n");
			else printf("false\n");
		}
		else if (years[yIdx] != Y && years[xIdx] == X) {
			if (query(Y, X - 1) < rains[xIdx]) printf("maybe\n");
			else printf("false\n");
		}
		else { // years[yIdx] == Y && years[xIdx == X]
			if (rains[xIdx] <= rains[yIdx] && query(Y + 1, X - 1) < rains[xIdx]) {
				if (X - Y == xIdx - yIdx) printf("true\n");
				else printf("maybe\n");
			}
			else printf("false\n");
		}
	}

	return 0;
}
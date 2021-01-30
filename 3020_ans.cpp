#include <cstdio>

#define MAX_N		100000
#define SZ_TR		1048576

int OFFSET, tree[SZ_TR];

void init(int N) {
	for (OFFSET = 1; OFFSET <= N; OFFSET *= 2);
}

void update(int from, int to) {
	from += OFFSET, to += OFFSET;

	while (from <= to) {
		if (from % 2 == 1) ++tree[from++];
		if (to % 2 == 0) ++tree[to--];

		from /= 2, to /= 2;
	}
}

int query(int idx) {
	int res = 0;

	idx += OFFSET;

	while (idx > 0) {
		res += tree[idx];
		idx /= 2;
	}
	return res;
}

int main() {
	int N, H, i, h, c;
	int ans, cnt;

	scanf("%d %d", &N, &H);
	
	init(H);
	
	for (i = 0; i < N; ++i) {
		scanf("%d", &h);
		if (i % 2 == 1) update(H - h + 1, H);
		else update(1, h);
	}

	ans = N + 1; // INF
	cnt = 0;

	for (h = 1; h < H; ++h) {
		c = query(h);
		if (c < ans)
			ans = c, cnt = 1;
		else if (c == ans)
			cnt++;
	}

	printf("%d %d\n", ans, cnt);

	return 0;
}


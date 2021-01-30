// 인덱스 트리 외에 "누적합" 방식으로도 풀 수 있다. (segmentation tree with lazy propagation)
// 한 번에 업데이트하는 것이 아니라 필요한 부분에만 마킹을 해 두고, 실제로 구하는 것은 나중에 해당 마킹을 필요한 부분에 전파시켜가면서 구하기 때문에 lazy propagation 이라는 이름이 붙었다.

#include <cstdio>

#define MAX_N		100000
#define SZ_TR		1048576

int OFFSET, tree[SZ_TR];

void init(int N) {
	for (OFFSET = 1; OFFSET <= N; OFFSET *= 2);
}

int main() {
	int N, H, i, h, sum = 0;
	int ans, cnt;

	scanf("%d %d", &N, &H);

	init(H);

	for (i = 0; i < N; ++i) {
		scanf("%d", &h);
		if (i % 2 == 1) ++tree[H - h + 1];
		else ++tree[1], --tree[h + 1];
	}

	ans = N + 1; // INF
	cnt = 0;

	for (h = 1; h < H; ++h) {
		sum = tree[h];
		if (sum < ans)
			ans = sum, cnt = 1;
		else if (sum == ans)
			cnt++;
	}

	printf("%d %d\n", ans, cnt);

	return 0;
}

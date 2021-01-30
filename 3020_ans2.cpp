// �ε��� Ʈ�� �ܿ� "������" ������ε� Ǯ �� �ִ�. (segmentation tree with lazy propagation)
// �� ���� ������Ʈ�ϴ� ���� �ƴ϶� �ʿ��� �κп��� ��ŷ�� �� �ΰ�, ������ ���ϴ� ���� ���߿� �ش� ��ŷ�� �ʿ��� �κп� ���Ľ��Ѱ��鼭 ���ϱ� ������ lazy propagation �̶�� �̸��� �پ���.

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

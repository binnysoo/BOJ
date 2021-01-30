#include <cstdio>

#define MAX_N		100000
#define SZ_TR		2097152
#define OFFSET		1048576

int tree[SZ_TR];

void update(int idx, int cnt) {
	idx += OFFSET; // leaf node

	while (idx > 0) {
		tree[idx] += cnt;
		idx /= 2;
	}
}

// findKth 호출 후 update(idx-OFFSET, -1) 을 호출하여 사탕 개수 업데이트 필요
int findKth(int kth) {
	int idx = 1, left, right;

	while (idx < OFFSET) {
		left = idx * 2, right = left + 1;
		if (tree[left] >= kth) idx = left;
		else kth -= tree[left], idx = right;
	}

	return idx - OFFSET;
}

int main() {
	
	return 0;
}
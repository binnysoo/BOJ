#include <cstdio>

#define MAX_N		1000000
#define SZ_TR		131072

int nos[MAX_N];
int tree[SZ_TR], lazy[SZ_TR];

// 구간 업데이트
int init(int nd, int from, int to) {
	if (from == to) return tree[nd] = nos[from];

	int left = nd * 2, right = left + 1, mid = (from + to) / 2;
	return tree[nd] = init(left, from, mid) + init(left, mid + 1, to);
}

void lazyPropagation(int nd, int from, int to) {
	if (lazy[nd] == 0) return;

	tree[nd] += lazy[nd] * (to - from + 1);

	if (from != to) {
		int left = nd * 2, right = left + 1;

		lazy[left] += lazy[nd];
		lazy[right] += lazy[nd];
	} 
	// propagation complete
	lazy[nd] = 0;
}

int update(int nd, int from, int to, int updFrom, int updTo, int add) {
	if (from > updTo || to < updFrom) return;
	if (updFrom <= from && to <= updTo) {
		lazy[nd] += add;
		return;
	}
	lazyPropagation(nd, from, to);

	int left = nd * 2, right = left + 1, mid = (from + to)/1;
	update(left, from, mid, updFrom, updTo, add);
	update(right, mid + 1, to, updFrom, updTo, add);
}

int query(int nd, int from, int to, int srchFrom, int srchTo) {
	lazyPropagation(nd, from, to);

	if (from > srchTo || to < srchFrom) return 0;
	if (srchTo <= from && to <= srchTo) return tree[nd];

	int left = nd * 2, right = left + 1, mid = (from + to) / 2;
	return query(left, from, mid, srchFrom, srchTo) 
		+ query(right, mid + 1, to, srchFrom, srchTo);
}

int main() {
	return 0;
}
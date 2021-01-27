#include <iostream>
#include <vector>

using namespace std;

int N;
char tree[27] = { '.', };
int idx[26] = { 0, };

void pre(int root) {
	if (tree[root] == '.')
		return;
	cout << tree[root];
	pre(root * 2);
	pre(root * 2 + 1);
}

void mid(int root) {
	if (tree[root] == '.')
		return;
	mid(root * 2);
	cout << tree[root];
	mid(root * 2 + 1);
}

void post(int root) {
	if (tree[root] == '.')
		return;
	post(root * 2);
	post(root * 2 + 1);
	cout << tree[root];
}

int main() {
	int i, root = 1;
	char p, l, r;
	cin >> N;

	idx[0] = root;

	for (i = 0; i < N; ++i) {
		cin >> p >> l >> r;
		root = idx[p - 'A'];
		tree[root] = p;
		tree[root * 2] = l;
		tree[root * 2 + 1] = r;
		
		idx[p - 'A'] = root;
		if (l != '.')
			idx[l - 'A'] = root * 2;
		if (r != '.')
			idx[r - 'A'] = root * 2 + 1;
	}
	pre(1);
	cout << "\n";
	mid(1);
	cout << "\n";
	post(1);
}
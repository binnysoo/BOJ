#include <iostream>
#include <vector>

using namespace std;


int parent[1000001];

int find(int a) {
	if (parent[a] == a) return parent[a];
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int aa = find(a);
	int bb = find(b);

	if (aa == bb) return; // already in the same group
	parent[bb] = parent[aa];
}

int main() {
	int n, m;
	int code, a, b, i;
	vector<int> ans;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	for (i = 0; i < m; ++i) {
		cin >> code >> a >> b;
		switch (code) {
		case 0:
			merge(a, b);
			break;
		case 1:
			if (find(a) == find(b))
				ans.push_back(1);
			else
				ans.push_back(0);
			break;
		}
	}

	for (i = 0; i < ans.size(); ++i) {
		if (ans[i] == 1)
			cout << "YES";
		else
			cout << "NO";
		if (i != ans.size() - 1) cout << "\n";
	}

	return 0;
}
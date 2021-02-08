#include <iostream>
#include <vector>
#define MAX		100001
using namespace std;

int arr[MAX], add[MAX];

int go(int x) {
	if (add[x] != -1) return add[x];
	add[x] = arr[x] + go(x - 1);
 	return add[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, i, start, end;
	vector<int> ans;

	cin >> N >> M;
	for (i = 1; i <= N; ++i) {
		cin >> arr[i];
		add[i] = -1;
	}
	add[0] = 0;
	add[1] = arr[1];
	for (i = 0; i < M; ++i) {
		cin >> start >> end;
		ans.push_back(go(end) - go(start-1));
	}
	for (i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i != ans.size() - 1) cout << '\n';
	}
	return 0;
}
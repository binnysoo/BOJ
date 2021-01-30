#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pqL, pqH;

int main() {
	int N, n;

	scanf("$d", &N);

	scanf("%d", &n);
	pqL.push(n);
	printf("%d\n", n);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &n);
		if (n > pqL.top()) {
			pqH.push(-n);
		}
		else {
			pqL.push(n);
		}

		if (pqH.size() > pqL.size())
			pqL.push(-pqH.top()), pqH.pop();

		else if (pqH.size() < pqL.size() - 1)
			pqH.push(-pqL.top()), pqL.pop();

		
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 500001

using namespace std;

int N;
int line[MAX] = { 0, };
int* arr, * arr2, *val;


int main() {
	int i, a, b;
	cin >> N; 
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		line[a] = b;
	}
	
	arr = new int[N]; arr2 = new int[N];
	val = new int[N]; //fill(val, val + N, 1);
	int idx = 0;
	for (i = 1; i < MAX; i++) {
		if (line[i] != 0) {
			arr[idx] = line[i];
			arr2[idx++] = line[i];
		}
	}
	int len = 1;
	for (i = 0; i < N; i++) {
		int cur = arr[i];
		auto pos = lower_bound(arr2, arr2 + N, cur);
		*pos = cur;
		if (pos == arr2 + N)
			len++;
	}
	cout << len << endl;

}

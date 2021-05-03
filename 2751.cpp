#include <cstdio>
#define MAX_SZ		1000001

int N;
int arr[MAX_SZ];

void merge_sort(int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	merge_sort(l, m);
	merge_sort(m + 1, r);

	// merge
	int L[MAX_SZ], R[MAX_SZ];
	int lidx = m - l + 1;
	int ridx = r - m;
	for (int i = 0; i < lidx; ++i) L[i] = arr[i + l];
	for (int j = 0; j < ridx; ++j) R[j] = arr[m + j + 1];

	int i = 0, j = 0, k = l;
	while (i < lidx&&j < ridx) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < lidx) {
		arr[k] = L[i];
		i++; k++;
	}
	while (j < ridx) {
		arr[k] = R[j];
		j++; k++;
	}

}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf(" %d", &arr[i]);
	}
	merge_sort(0, N - 1);
	for (int i = 0; i < N; ++i) {
		printf("%d\n", arr[i]);
	}


	return 0;
}
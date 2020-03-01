#include <stdio.h>
#define MAX_SIZE 1000001
#define MAX_NUM 1000000

void init(int *my_array) {
	for (int i = 0; i <= 1000001; i++) {
		my_array[i] = MAX_NUM;
	}
	my_array[1] = 0;
	my_array[2] = 1;
	my_array[3] = 1;

	return 0;
}

int min2(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int min3(int a, int b, int c) {
	
	if (a > b) {
		if (b > c) return c;
		else return b;
	}
	else {
		if (a > c) return c;
		else return a;
	}

}

int calculator(int N, int *my_array) {

	int newN = N;
	int oldCalCount = MAX_NUM;

	if (my_array[N] != MAX_NUM)							// N�� ���Ͽ� ����� Ƚ���� ������ �� ��ȯ
		return my_array[N];
	else {												// N�� ���Ͽ� ����� Ƚ���� ������	

		if (N % 6 == 0) {
			if (my_array[N / 2] == MAX_NUM)
				my_array[N / 2] = calculator(N / 2, my_array);
			if (my_array[N / 3] == MAX_NUM)
				my_array[N / 3] = calculator(N / 3, my_array);
			if (my_array[N - 1] == MAX_NUM)
				my_array[N - 1] = calculator(N - 1, my_array);
			my_array[N] = min3(my_array[N / 2], my_array[N / 3], my_array[N - 1]) + 1;
		}
		else if (N % 3 == 0) {  
			if (my_array[N / 3] == MAX_NUM)
				my_array[N / 3] = calculator(N / 3, my_array);
			if (my_array[N - 1] == MAX_NUM)
				my_array[N - 1] = calculator(N - 1, my_array);
			my_array[N] = min2(my_array[N / 3], my_array[N - 1]) + 1;
		}
		else if (N % 2 == 0) {
			if (my_array[N / 2] == MAX_NUM)
				my_array[N / 2] = calculator(N / 2, my_array);
			if (my_array[N - 1] == MAX_NUM)
				my_array[N - 1] = calculator(N - 1, my_array);
			my_array[N] = min2(my_array[N / 2], my_array[N - 1]) + 1;
		}
		else {
			if (my_array[N - 1] == MAX_NUM)
				my_array[N - 1] = calculator(N - 1, my_array);
			my_array[N] = my_array[N - 1] + 1;
		}
	}

	return my_array[N];
}

int main() {

	int N, calCount;
	int *calMap = (int *)malloc(sizeof(int)*MAX_SIZE);				// �־��� N�� ���Ͽ� 1�� ����� ���� �ʿ��� �ּ� ������ Ƚ�� ����

	init(calMap);													// initiate

	scanf("%d", &N);												// �Էµ� N�� ����, 1 <= N <= 10^6
	calCount = calculator(N, calMap);
	printf("%d", calCount);

	return 0;
}
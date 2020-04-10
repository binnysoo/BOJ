#include <stdio.h>

//enum { push, pop, size ,empty, front, back };
int queue[10000];
int front = 0, back = 0;

int main(void)
{
	int N, i, num;
	char x[10];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &x);

		if (x[0] == 'p' && x[1] == 'u') {
			scanf("%d", &num);
			queue[back++] = num;
		}
		else if (x[0] == 'p' && x[1] == 'o') {
			if (front == back) num = -1;
			else num = queue[front++];
			printf("%d\n", num);
		}
		else if (x[0] == 's') {
			num = back - front;
			printf("%d\n", num);
		}
		else if (x[0] == 'e') {
			if (front == back) num = 1;
			else num = 0;
			printf("%d\n", num);
		}
		else if (x[0] == 'f') {
			if (front == back) num = -1;
			else num = queue[front];
			printf("%d\n", num);
		}
		else if (x[0] == 'b') {
			if (front == back) num = -1;
			else num = queue[back - 1];
			printf("%d\n", num);
		}
	}

	return 0;
}
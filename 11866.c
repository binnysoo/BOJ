#include <stdio.h>

/* circular queue */
typedef struct _data* dataptr;
typedef struct _data {
	int index;
	dataptr next;
}data;

dataptr front = NULL;
dataptr rear = NULL;

void enqueue(int x) {
	dataptr new_data;
	new_data = (dataptr)malloc(sizeof(data));
	new_data->index = x;

	if (front == NULL) {
		front = new_data; rear = new_data;
	}
	
	new_data->next = front;
	rear->next = new_data;
	rear = new_data;

	return;
}

int dequeue() {
	int num;
	dataptr tmp;

	num = front->index;
	tmp = front;
	front = front->next;
	free(tmp);

	return num;
}



int main() {
	int N, K;
	int i, count = 1;

	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) enqueue(i);
	
	printf("<");
	while (front != rear) {
		if (count++ == K) {
			printf("%d, ", dequeue());
			count = 1;
		}
		else {
			enqueue(dequeue());
		}
	}
	printf("%d>", dequeue());

	return 0;
}
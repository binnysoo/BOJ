#include <stdio.h>

/* circular queue */
typedef struct _q* qp;
typedef struct _q {
	int num;
	qp next;
}q;

qp front = NULL;
qp rear = NULL;

void enqueue(int x) {
	qp newq;
	newq = (qp)malloc(sizeof(q));
	newq->num = x;

	if (front == NULL) {
		front = newq; rear = newq;
	}

	newq->next = front;
	rear->next = newq;
	rear = newq;

	return;
}

int dequeue() {
	int num;
	qp tmp;
	if (front == NULL && rear == NULL) {
		printf("queue empty\n");
		return -1;
	}
	if (front == rear) {
		num = front->num;
		front = NULL; rear = NULL;
		return num;
	}
	num = front->num;
	tmp = front;
	front = front->next;
	rear->next = front;
	free(tmp);
	return num;
}


int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) enqueue(i);
	while (rear != front) {
		dequeue();
		enqueue(dequeue());
	}
	printf("%d", dequeue());
	return 0;
}
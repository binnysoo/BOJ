#include <stdio.h>
#include <string.h>
#define MAX_COMM 11

typedef enum _comm{
	PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK
}comm;

/* deque */
typedef struct _deq* deqptr;
typedef struct _deq {
	int num;
	deqptr prev;
	deqptr next;
}deq;
deqptr head = NULL;
deqptr rear = NULL;

// head == rear 일 때 empty 임을 알 수 있는 구현 방법은 ??? 
// (지금은 head == empty (!= NULL) 이면 element 1개)

void push_front(int x){
	deqptr newdeq;
	
	newdeq = (deqptr)malloc(sizeof(deq));
	newdeq->num = x;

	if (head == NULL || rear == NULL) {
		head = newdeq; rear = newdeq;
	}

	newdeq->prev = rear;
	newdeq->next = head;
	rear->next = newdeq;
	head->prev = newdeq;
	head = newdeq;
	return;
}

void push_back(int x) {
	deqptr newdeq;

	newdeq = (deqptr)malloc(sizeof(deq));
	newdeq->num = x;

	if (head == NULL || rear == NULL) {
		head = newdeq; rear = newdeq;
	}

	newdeq->prev = rear;
	newdeq->next = head;
	rear->next = newdeq;
	head->prev = newdeq;
	rear = newdeq;
	return;
}

int pop_front() {
	deqptr tmp;
	int x;
	if (head == NULL || rear == NULL) {
		return -1;
	}
	else { 
		if (head == rear) { // empty() 를 쓰는게 나은지 ?
			x = head->num;
			free(head);
			head = NULL; rear = NULL;
		}
		else {
			x = head->num;
			tmp = head;

			head = head->next;
			head->prev = rear;
			rear->next = head;

			free(tmp);
		}
	}

	return x;
}

int pop_back() {
	deqptr tmp;
	int x;
	if (head == NULL || rear == NULL) {
		return -1;
	}
	else {
		if (head == rear) { 
			x = rear->num;
			free(rear);
			head = NULL; rear = NULL;
		}
		else {
			x = rear->num;
			tmp = rear;

			rear = rear->prev;
			rear->next = head;
			head->prev = rear;

			free(tmp);
		}
	}

	return x;
}

int size() {
	deqptr tmp = head;
	int x = 1;

	if (head == NULL && rear == NULL)
		x = 0;
	else {
		while (tmp != rear) {
			tmp = tmp->next;
			x++;
		}
	}

	return x;
}

int empty() {
	if (head == NULL || rear == NULL)
		return 1;
	else
		return 0;
}

int front() {
	if (head == NULL)
		return -1;
	else
		return head->num;
}

int back() {
	if (rear == NULL)
		return -1;
	else
		return rear->num;
}

comm getComm() {
	char command[MAX_COMM];
	scanf("%s", command);
	if (!strcmp("push_front", command))
		return PUSH_FRONT;
	else if (!strcmp("push_back", command))
		return PUSH_BACK;
	else if (!strcmp("pop_front", command))
		return POP_FRONT;
	else if (!strcmp("pop_back", command))
		return POP_BACK;
	else if (!strcmp("size", command))
		return SIZE;
	else if (!strcmp("empty", command))
		return EMPTY;
	else if (!strcmp("front", command))
		return FRONT;
	else if (!strcmp("back", command))
		return BACK;
}

int main() {
	int N, i, x;
	char command[MAX_COMM];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		switch (getComm()) {
		case PUSH_FRONT: 
			scanf("%d", &x);
			push_front(x);
			break;
		case PUSH_BACK:
			scanf("%d", &x);
			push_back(x);
			break;
		case POP_FRONT:
			printf("%d\n", pop_front());
			break;
		case POP_BACK:
			printf("%d\n", pop_back());
			break;
		case SIZE:
			printf("%d\n", size());
			break;
		case EMPTY:
			printf("%d\n", empty());
			break;
		case FRONT:
			printf("%d\n", front());
			break;
		case BACK:
			printf("%d\n", back());
			break;
		default:
			break;
		}
	}

	return 0;
}
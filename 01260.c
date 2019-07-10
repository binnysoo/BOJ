#include <stdio.h>
#define TRUE 1
#define FALSE 0

short int real_graph[1001][1001] = { 0 };
short int graph[1001][1001] = { 0 };

int stack[1000];
int top = -1;
int queue[1000];
int front = -1; back = -1;

void DFS(short int[][1001], int N, int V);
void BFS(short int[][1001], int N, int V);
void stack_push(int stack[], int x);
int stack_pop(void);
void queue_push(int queue[], int x);
int queue_pop(void);

int main(void)
{
	int N, M, V; 
	int i, j, k;
	
	/*
	N: number of vertex
	M: number of edge
	V: starting point
	*/


	scanf("%d %d %d", &N, &M, &V);

	for (i = 0; i <= N; i++) {
		//initialize
		real_graph[0][i] = i;
		real_graph[i][0] = i;
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		real_graph[j][k] = TRUE;
		real_graph[k][j] = TRUE;
	}

	/* DFS */
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			graph[i][j] = real_graph[i][j];
		}
	}
	DFS(graph, N, V);

	printf("\n");

	/* BFS */
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			graph[i][j] = real_graph[i][j];
		}
	}
	BFS(graph, N, V);

	return 0;
}
void DFS(short int graph[][1001], int N, int V)
{
	int i, j, k;
	int x;

	stack_push(stack, V);
	for (k = 0; k <= N; k++) {
		// 이미 방문한 노드 재방문 방지
		graph[k][V] = FALSE;
	}

	for (i = V; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (graph[i][j] == TRUE) {
				stack_push(stack, j);
				for (k = 0; k <= N; k++) {
					// 이미 방문한 노드 재방문 방지
					graph[k][j] = FALSE;
				}
				i = j-1;
				break;
			}
			if (j == N) {
				i = stack_pop() - 1;
			}
		}
		if (i == V - 1) break;
	}


	return;
}
void BFS(short int graph[][1001], int N, int V)
{
	int i, j, k;
	int x;
	
	queue_push(queue, V);
	for (k = 0; k <= N; k++) {
		// 이미 방문한 노드 재방문 방지
		graph[k][V] = FALSE;
	}

	for (i = queue_pop(); i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (graph[i][j] == TRUE) {
				queue_push(queue, j);
				for (k = 0; k <= N; k++) {
					// 이미 방문한 노드 재방문 방지
					graph[k][j] = FALSE;
				}
			}
			if (j == N) {
				i = queue_pop() - 1;
			}
		}
		if (front == back) break;
	}

	return;
}
void stack_push(int stack[], int x)
{
	stack[++top] = x;
	printf("%d ", x);
	return;
}
int stack_pop(void)
{
	int value;

	if (top == -1) {
		printf("STACK IS EMPTY\n");
		return;
	}
	else
		value = stack[top--];

	return value;
}
void queue_push(int queue[], int x)
{
	queue[++back] = x;
	printf("%d ", x);
	return;
}
int queue_pop(void)
{
	int value;

	if (front == back) {
		printf("QUEUE IS EMPTY\n");
		return;
	}
	else
		value = queue[++front];

	return value;
}

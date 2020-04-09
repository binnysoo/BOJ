#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 51

/* Global Variables */
char stack[MAX_SIZE];
char paren[MAX_SIZE];
int top = -1;

/* stack */
void push(char x) {
	if (top > MAX_SIZE) {
		printf("STACK IS FULL\n\n");
		return;
	}
	stack[++top] = x;

	return;
}

char pop() {
	if (top == -1) {
		printf("STACK IS EMPTY\n\n");
		return -1;
	}
	return stack[top--];
}

void init(char stack[MAX_SIZE]) {
	int i;
	top = -1;
	for(i=0;i<MAX_SIZE;i++) stack[i] = '\0';
	return;
}

int main()
{
	int T;
	int i, j, flag;

	scanf("%d\n", &T);
	for (i = 0; i < T; i++) {
		init(stack); init(paren);
		scanf("%s", paren);
		j = 0; flag = 0;
		while (paren[j] != '\0') {
			if (paren[j] == '(') push(paren[j]);
			else if (paren[j] == ')') {
				if (top != -1) {
					if (stack[top] == '(') pop();
				}
				else {
					printf("NO\n");
					flag = 1;
					break;
				}
			}
			j++;
		}
		if (!flag) {
			if (top == -1) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}
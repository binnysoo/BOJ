#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

/*Global variable*/
int stack[MAX_SIZE];
int stacktop = -1;

/*functions*/
void push(int);
int pop(void);
int size(void);
int empty(void);
int top(void);

int main(void)
{
	int num, i, x;
	char inst[6] = "0";

	
	//printf("Enter the number of instructions to execute (1 <= N <= 10000) : ");
	scanf("%d", &num);

	if (1 <= num && num <= 10000) {

		for (i = 0; i < num; i++) {
			scanf("%s", inst);

			if (inst[0] == 'p' && inst[1] == 'u' && inst[2] == 's' && inst[3] == 'h') {
				scanf("%d", &x);
				push(x);
			}

			else if (inst[0] == 'p' && inst[1] == 'o' && inst[2] == 'p') {
				pop();
			}

			else if (inst[0] == 's' && inst[1] == 'i' && inst[2] == 'z' && inst[3] == 'e') {
				size();
			}

			else if (inst[0] == 'e' && inst[1] == 'm' && inst[2] == 'p' && inst[3] == 't') {
				empty();
			}

			else if (inst[0] == 't' && inst[1] == 'o' && inst[2] == 'p') {
				top();
			}

			else
				printf("Invalid instruction.\n");

		}
	}


	return 0;
}

void push(int x)
{
	if (1 <= x && x <= 100000) {
		stack[++stacktop] = x;
	}

	return;
}

int pop(void)
{
	int tmp;

	if (stacktop != -1) {
		tmp = stack[stacktop];
		stacktop--;
	}

	else
		tmp = -1;


	printf("%d\n", tmp);

	return tmp;
}

int size(void)
{
	int tmp = stacktop;
	tmp++;
	printf("%d\n", tmp);


	return tmp;
}

int  empty(void)
{
	int tmp;

	if (stacktop == -1) tmp = 1;
	else tmp = 0;

	printf("%d\n", tmp);


	return tmp;
}

int top(void)
{
	int tmp;

	if (stacktop != -1) tmp = stack[stacktop];
	else tmp = -1;
	
	printf("%d\n", tmp);


	return tmp;
}
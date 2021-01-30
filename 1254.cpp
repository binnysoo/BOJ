#include <cstdio>
#include <string.h>

int main() {
	char c;
	int n, cnt, i, j, add;
	char string[1001], reverse[1001];

	n = 0;
	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;
		string[n++] = c;
	}
	string[n] = '\0';
	for (i = 0; i < n; i++) {
		reverse[n - i - 1] = string[i];
	}
	reverse[n] = '\0';

	cnt = 0; i = 0; j = 0;
	while (i < n) {
		if (string[i] != reverse[j]) {
			i = ++cnt; 
			j = 0;
		}
		else {
			++i; ++j;
		}
	}

	add = n - j;
	
	printf("%d", n + add);
}
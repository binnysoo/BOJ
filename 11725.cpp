#include <iostream>
#include <stack>

#define index(a) (int)a - (int)'A'

using namespace std;

typedef struct _node {
	char label;
	char left;
	char right;
}node;

int main() {
	int i;
	int n;
	char cur;
	node tmp;
	node *tree;
	stack<node> s;
	
	cin >> n;
	tree = new node[n];
	for (i = 0; i < n; i++) {
		cin >> tmp.label >> tmp.left >> tmp.right;
		tree[index(i)] = tmp;
	}

	s.push(tree[0]);
	while (!s.empty()) {
		

	}

}
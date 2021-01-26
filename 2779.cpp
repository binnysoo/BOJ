#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, N;
string sen;
vector<string> word;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j;
	string tmp;
	
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> sen;
		cin >> N;
		for (j = 0; j < N; j++) {
			cin >> tmp;
			word.push_back(tmp);
		}
	}
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> letters;
vector<vector<char>> ans;

bool check(vector<char> pw) {
	int consonant = 0, vowel = 0;
	for (char c : pw) {
		switch (c) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++vowel;
				break;
			default:
				++consonant;
				break;
		}
		if (consonant >= 2 && vowel >= 1) 
			return true;
	}
	return false;
}

void comb(vector<char> pw, int idx) {

	if (pw.size() == L) {
		if (check(pw))
			ans.push_back(pw);
	}
	else {
		if (idx > letters.size() - 1) return;

		pw.push_back(letters[idx]);
		comb(pw, idx + 1);
		pw.pop_back();
		comb(pw, idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i;
	char tmp;
	vector<char> pw;

	cin >> L >> C;
	for (i = 0; i < C; ++i) {
		cin >> tmp;
		letters.push_back(tmp);
	}

	sort(letters.begin(), letters.end());

	comb(pw, 0);

	for (i = 0; i < ans.size(); ++i) {
		for (char c : ans[i]) {
			cout << c;
		}
		cout << '\n';
	}
}
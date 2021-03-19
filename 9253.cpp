#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A, B, ans;
int a, b, n;
int fail[200001];
vector<int> result;

int main() {
	cin >> A >> B >> ans;
	a = A.length();
	b = B.length();
    n = ans.length();

    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && ans[i] != ans[j]) j = fail[j - 1];
        if (ans[i] == ans[j]) fail[i] = ++j;
    }


    vector<int> result;
    for (int i = 0, j = 0; i < a; i++) {
        while (j > 0 && A[i] != ans[j]) j = fail[j - 1];
        if (A[i] == ans[j]) {
            if (j == n - 1) {
                result.push_back(i - n + 2);
                j = fail[j];
            }
            else j++;
        }
    }

    if (result.size() == 0) cout << "NO";
    else cout << "YES";

	return 0;
}
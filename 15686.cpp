#include <iostream>
#include <vector>

#define HOUSE 1
#define CHICKEN 2

using namespace std;

int N, M;
vector<pair<int, int>> h_coord; // house
vector<pair<int, int>> c_coord; // chicken
vector<int> comb;
vector<int> selected;
bool visited[13] = { false, };


int get_dist(pair<int, int> a, pair<int, int> b) {
	int x, y;
	//return (abs(a.first - b.first) + abs(a.second = b.second));
	x = abs(a.first - b.first);
	y = abs(a.second - b.second);
	return x + y;
}

int get_min_dist() {
	// calculate minimum distance between the selected chickens and the houses
	int i, j, closest, tmp, total = 0;
	for (i = 0; i < h_coord.size(); i++) {
		closest = 1000000000;
		for (j = 0; j < selected.size(); j++) {
			tmp = get_dist(h_coord[i], c_coord[selected[j]]);
			if (tmp < closest) closest = tmp;
		}
		total += closest;
	}
	return total;
}


int go(int cur, int lv, int num) {
	int i, total = 0, tmp, min = 1000000000;
	
	if (lv == num) {
		// finished finding combination
		comb.push_back(get_min_dist());
	}
	else {
		for (i = cur; i < c_coord.size(); i++) {
			if (visited[i]) continue;
			visited[i] = true;
			selected.push_back(i);
			go(i, lv+1, num);
			visited[i] = false;
			selected.pop_back();
		}
	}
	return min;
}

int main() {
	int i, j, tmp, min = 1000000000;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == HOUSE) {
				h_coord.push_back(make_pair(i, j));
			}
			else if (tmp == CHICKEN) {
				c_coord.push_back(make_pair(i, j));
			}
		}
	}

	// choose 'M'
	go(0, 0, M);
	for (i = 0; i < comb.size(); i++) {
		if (comb[i] < min) min = comb[i];
	}

	cout << min;
	
}
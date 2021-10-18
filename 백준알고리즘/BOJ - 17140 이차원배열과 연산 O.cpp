// pair와 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check[107];
vector<vector<int> > v;
int r, c, k;
int map[101][101];
int row;
int col;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second == b.second) {
		return a.first > b.first;
	}
	else return false;

}

void cfun() {
	int nr = 0;
	for (int i = 0; i < col; i++) {
		pair<int, int > check[101] = { };
		int cnt = 0;
		for (int j = 0; j < row; j++) {
			int idx = map[j][i];
			if (idx == 0) continue;
			map[j][i] = 0;
			check[idx].first = idx;
			if (check[idx].second == 0) cnt++;
			check[idx].second++;
			
		}
		sort(check, check + 101, compare);
		int count = 0;
		for (int a = cnt -1; a >= 0; --a) {
			map[count++][i] = check[a].first;
			map[count++][i] = check[a].second;
			if(nr < count) nr = count;
		}
	}
	row = nr;
}
void rfun() {
	int  nc = 0;
	for (int i = 0; i < row; i++) {
		pair<int, int > check[101] = { };
		int cnt = 0;
		for (int j = 0; j < col; j++) {
			
			int idx = map[i][j];
			if (idx == 0) continue;
			map[i][j] = 0;
			check[idx].first = idx;
			if (check[idx].second == 0) cnt++;
			check[idx].second++;

		}
		sort(check, check + 101, compare);
		int count = 0;
		for (int a = cnt - 1; a >= 0; --a) {
			map[i][count++] = check[a].first;
			map[i][count++] = check[a].second;
			if (nc < count) nc = count;
		}
	}
	col = nc;
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	row = 3;
	col = 3;

	int cnt = 0;
	int res = -1;
	while (1) {
		if (map[r - 1][c - 1] == k) {
			res = cnt;
			break;
		}
		if (cnt == 100) break;
		if (row >= col) {
			rfun();
			int x = map[r-1][c-1];
		}
		else {
			cfun();
			int x = map[r - 1][c - 1];
		}
		cnt++;
		
	}

	cout << res << '\n';
}


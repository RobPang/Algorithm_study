#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int dirx[4] = { 0,0,-1,1 };
int diry[4] = { -1, 1, 0, 0 };
int n, m;
int d[100];
int s[100];
vector<int> cur_v;
vector<int> next_v;
int map[50][50];
int res;
void blizard (int d, int s) {
	int idx = 0;
	int sum = 0;
	if (d == 2) {
		sum = 1;
	}
	else if (d == 1) {
		sum = 3;
	}
	else if (d == 3) {
		sum = 5;
	}
	else if (d == 0) {
		sum = 7;
	}
	//cur_v[idx] = 0;
	for (int i = 0; i < s; i++) {
		idx += sum;
		sum += 8;
		if (idx >= cur_v.size()) break;
	//	res += cur_v[idx];
		cur_v[idx] = 0;
	}
}

void fill() {
	for (int i = 0; i < cur_v.size(); ) {
		if (cur_v[i] == 0) {
			cur_v.erase(cur_v.begin() + i);
		}
		else {
			i++;
		}
	}
}

void bomb() {
	int cnt = 0;
	int pre = cur_v[1];
	int idx = 2;
	for (int i = 2; i < cur_v.size();i++) {
		if (pre == cur_v[idx]) {
			cnt++;
		}
		else {
			if (cnt >= 4) {
				idx -= cnt;
				for(int j = 0; j < cnt; j++){
					res += cur_v[idx];
					cur_v.erase(cur_v.begin() + idx);
				}
			}
			cnt = 1;
		}
		pre = cur_v[idx];
		idx++;
	}
	if (cnt >= 4) {
		idx--;
		for (int j = 0; j < cnt; j++) {
			res += cur_v[idx];
			cur_v.erase(cur_v.begin() + idx);
		}
	}
}

void renew() {
	int cnt = 1;
	int pre = cur_v[1];
	int idx = 2;
	next_v.push_back(-1);
	for (int i = 2; i < cur_v.size(); i++) {
		if (pre == cur_v[idx]) {
			cnt++;
		}
		else {
			next_v.push_back(cnt);
			if (next_v.size() >= n * n) break;
			next_v.push_back(pre);
			if (next_v.size() >= n * n) break;
			cnt = 1;
		}
		pre = cur_v[idx];
		idx++;
	}

	if (idx == cur_v.size()) {
		next_v.push_back(cnt);
		next_v.push_back(pre);
	}
	for (int i = 0; i < cur_v.size(); i++) {
		cur_v.pop_back();
	}
	for (int i = 0; i < next_v.size(); i++) {
		int a = next_v[0];
		cur_v.push_back(a);
		next_v.erase(next_v.begin());
	}
}

int main() {
	res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int di;
		int si;
		cin >> di >> si;
		d[i] = di - 1;
		s[i] = si;
	}
	int mid = n / 2;
	//int midy = n / 2;
	int idx = 0;
	cur_v.push_back(-1);
	for (int i = 1; i <= n / 2; i++) {
		for (int y = mid - i + 1; y <= mid + i; y++) {
			cur_v.push_back(map[y][mid - i]);
		}
		for (int x = mid - i + 1; x <= mid + i; x++) {
			cur_v.push_back(map[mid +i][x]);
		}
		for (int y = mid + i - 1; y >= mid - i; --y) {
			cur_v.push_back(map[y][mid + i]);
		}
		for (int x = mid + i - 1;  x >= mid - i; --x) {
			cur_v.push_back(map[mid - i][x]);
		}
	}

	for (int i = 0; i < m; i++) {
		blizard(d[i], s[i]);
		fill();
		bomb();
		renew();
		int a = cur_v[i];
	}
	cout << res;

}
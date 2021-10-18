#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct TREE
{
	int y, x, year;
	
	bool operator<(const TREE t) const {
		return this->year > t.year;
	}

};

int map[10][10];
int add[10][10];

priority_queue<TREE> q[2];
int n, m, k;

int dirx[8] = { 1,1,1,0,-1,-1,-1,0 };
int diry[8] = { -1,0,1,1,1,0,-1,-1 };

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> add[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, year;
		cin >> x >> y >> year;
		TREE t;
		t.x = x -1 ; t.y = y-1; t.year = year;
		q[0].push(t);
	}
	int cur = 0;
	int next = 1;
	for (int i = 0; i < k; i++) {
		next = (cur+1) % 2;
		priority_queue<TREE> dead_tree;
		priority_queue<TREE> live_tree;

		while (!q[cur].empty()) {
			TREE t = q[cur].top();
			q[cur].pop();
			int y = t.y;
			int x = t.x;
			int year = t.year;
			if (map[y][x] >= year) {
				map[y][x] -= year;
				t.year = year+1;
				live_tree.push(t);
			}
			else {
				dead_tree.push(t);
			}
		}
		while (!dead_tree.empty()) {
			TREE t = dead_tree.top();
			dead_tree.pop();
			map[t.y][t.x] += t.year / 2;
		}
		while (!live_tree.empty()) {
			TREE t = live_tree.top();
			live_tree.pop();
			q[next].push(t);
			if (t.year % 5 == 0) {
				for (int dir = 0; dir < 8; dir++) {
					int ny = t.y + diry[dir];
					int nx = t.x + dirx[dir];

					if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
					TREE nt; nt.y = ny; nt.x = nx; nt.year = 1;
					q[next].push(nt);
				}
			}
		}

		for (int y = 0; y < n; y++) {
			for (int j = 0; j < n; j++) {
				map[y][j] += add[y][j];
			}
		}
		cur = next;
	}
	cout << q[cur].size();
}

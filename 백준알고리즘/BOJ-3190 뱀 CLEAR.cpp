// 뱀 - 무지성 구현 가능 queue를 사용해서 경로 기억하기
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];
int n, k, l;
char rot[10001];
int dirx[4] = { 1, 0 ,-1,0 };
int diry[4] = { 0, 1, 0, -1};

int bfs(int x, int y, int cnt) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	int dir = 0;
	int nx = x;
	int ny = y;
	map[x][y] = 2;
	while (1) {
		nx += dirx[dir];
		ny += diry[dir];
		cnt++;
		if (!(nx >= 1 && ny >= 1 && nx <= n && ny <= n)) break;
		if (map[ny][nx] == 2) break;
		
		if (map[ny][nx] != 1) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			map[b][a] = 0;
		}
		q.push({ nx, ny });
		map[ny][nx] = 2;
		if (rot[cnt] == 'L') {
			dir--;
			if (dir < 0) dir = 3;
		}
		else if (rot[cnt] == 'D') {
			dir++;
			if (dir == 4) dir = 0;
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int col;
		int row;
		cin >> col; cin >> row;
		map[col][row] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int idx;
		char a;
		cin >> idx; cin >> a;
		rot[idx] = a;
	}
	
	cout << bfs(1, 1, 0);
}
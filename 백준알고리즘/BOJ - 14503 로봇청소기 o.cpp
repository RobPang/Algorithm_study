// 로봇청소기 방향주의
#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int map[51][51];
bool check[51][51];
int n, m;
int dirx[4] = { 0,1,0,-1 };	//왼쪽 방향  -1 방향
int diry[4] = { -1,0,1,0 };
int sx, sy, sd;

void dfs(int x, int y, int dir) {
	map[y][x] = 2;
	check[y][x] = true;
	int flag = 0;
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		--dir;
		if (dir < 0) dir = 3;
		ny = y + diry[dir];
		nx = x + dirx[dir];
		if (!(nx >= 0 && ny >= 0 && nx < m && ny < n)) continue;

		if (map[ny][nx] != 1 && map[ny][nx] != 2 && !check[ny][nx]) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		dfs(nx, ny, dir);
	}
	else {
		int ny1 = y - diry[dir];
		int nx1 = x - dirx[dir];
		if (!(nx1 >= 0 && ny1 >= 0 && nx1 < m && ny1 < n)) return;
		if (map[ny1][nx1] == 1) return;
		dfs(nx1, ny1, dir);
	}
	
	return;
}

int main() {
	cin >> n >> m;

	cin >> sy >> sx >> sd;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}


	dfs(sx, sy, sd);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) cnt++;
		}
	}
	cout << cnt;
}
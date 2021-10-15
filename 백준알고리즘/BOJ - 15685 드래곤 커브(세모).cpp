//드래곤 커브 - 경로기억 회전은 결로 역으로 따라가면서 값 추가
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int map[101][101];
int dirx[4] = {1,0,-1,0};
int diry[4] = {0,-1,0,1}; 
int sqr[2][2] = { 1,1,1,1 };

struct DRAGON {
	int x, y, d, g;
};

DRAGON  dragon[21];

void bfs(DRAGON dra) {
	int path[1025] = { 0 };
	path[0] = dra.d;
	int size;
	int idx = 0;
	for (int i = 0; i < dra.g; i++) {
		size = idx;
		for (int j = size ; j >= 0; --j) {
			path[++idx] = (path[j]+1)%4;
		}
	}
	map[dra.y][dra.x] = 1;
	int ny = dra.y;
	int nx = dra.x;
	for (int i = 0; i <= idx; i++) {
		ny += diry[path[i]];
		nx += dirx[path[i]];
		map[ny][nx] = 1;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dragon[i].x >> dragon[i].y >> dragon[i].d >> dragon[i].g;
	}
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; i++) {
		bfs(dragon[i]);
	}
	int cnt = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1 && map[y + 1][x] == 1 && map[y][x + 1] == 1 && map[y + 1][x + 1] == 1) cnt++;
		}
	}
	cout << cnt << '\n';
}
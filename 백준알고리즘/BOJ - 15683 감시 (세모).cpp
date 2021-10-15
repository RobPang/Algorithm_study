// 감시 - 구현 어렵다 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
int map[8][8];
int backup[8][8];
int dirx[4] = { 1,-1,0,0, };
int diry[4] = { 0,0,1,-1 };

struct CCTV {
	int type;
	int x, y;

};
CCTV camera[8];
int camera_size;
int dir_size[5] = { 4,2,4,4,1 };
int res;
void update(int dir, CCTV camera) {
	dir = (dir % 4);
	if (dir == 0) {
		for (int x = camera.x + 1; x < m; x++) {
			if (map[camera.y][x] == 6) break;
			map[camera.y][x] = -1;
		}
	}
	if (dir == 1) {
		for (int y = camera.y + 1; y < n; y++) {
			if (map[y][camera.x] == 6) break;
			map[y][camera.x] = -1;
		}
	}
	if (dir == 2) {
		for (int x = camera.x - 1; x >= 0; --x) {
			if (map[camera.y][x] == 6) break;
			map[camera.y][x] = -1;
		}
	}
	if (dir == 3) {
		for (int y = camera.y - 1; y >= 0; --y) {
			if (map[y][camera.x] == 6) break;
			map[y][camera.x] = -1;
		}
	}

}

void copy(int target[8][8], int in[8][8]) {
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			target[y][x] = in[y][x];
		}
	}
}

void dfs(int camera_cnt) {
	if (camera_cnt == camera_size) {
		int cnt = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (map[y][x] == 0){
					cnt++;
				}
			}
		}
		if (res > cnt) {
			res = cnt;
		}
		return ;
	}
	int type = camera[camera_cnt].type;
	for (int i = 0; i < dir_size[type]; i++) {
		int temp[8][8];
		copy(temp, map);
		if (type == 0) {
			update(i, camera[camera_cnt]);
		}
		else if (type == 1) {
			update(i, camera[camera_cnt]);
			update(i + 2, camera[camera_cnt]);
		}
		else if (type == 2) {
			update(i, camera[camera_cnt]);
			update(i + 1, camera[camera_cnt]);
			
		}
		else if (type == 3) {
			update(i, camera[camera_cnt]);
			update(i + 1, camera[camera_cnt]);
			update(i + 2, camera[camera_cnt]);
		}
		else if (type == 4) {
			update(i, camera[camera_cnt]);
			update(i + 1, camera[camera_cnt]);
			update(i + 2, camera[camera_cnt]);
			update(i + 3, camera[camera_cnt]);
		}
		dfs(camera_cnt + 1);
		copy(map, temp);
	}

}

int main() {
	cin >> n >> m;
	camera_size = 0;
	res = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 6 && map[i][j] != 0) {

				camera[camera_size].type = map[i][j] - 1;
				camera[camera_size].y = i;
				camera[camera_size].x = j;
				camera_size++;
			}
		}
	}

	dfs(0);
	cout << res << '\n';
}
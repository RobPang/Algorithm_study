//공기 청정기 - 그저 구현 
#include <iostream>

using namespace std;

int map[51][51];
int r, c, t;

int dirx[4] = { 1, 0, -1, 0 };
int diry[4] = { 0, -1, 0, 1 };

void expend() {
	int temp[51][51] = { 0 };
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (map[y][x] != 0 && map[y][x] != -1) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int ny = y + diry[dir];
					int nx = x + dirx[dir];
					if (!(nx >= 0 && ny >= 0 && ny < r && nx < c)) continue;
					if (map[ny][nx] == -1) {
						temp[ny][nx] = -1;
						continue;
					} 
					cnt++;
					temp[ny][nx] += map[y][x] / 5;
				}
				temp[y][x] += map[y][x] -(map[y][x] / 5) * cnt;
			}
		}
	}

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			map[y][x] = temp[y][x];
		}
	}
}


int main() {

	cin >> r >> c >> t;
	int up;
	int down;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				down = i;
			}
		}
	}
	up = down - 1;
	while (t) {
		t--;
		expend();
		map[up][0] = -1;
		map[down][0] = -1;
		for (int i = up - 2; i >=0 ; i--) {
			map[i+1][0] = map[i][0];
		}
		for (int i = 0; i < c; ++i) {
			map[0][i] = map[0][i+1];
		}
		for (int i = 0 ; i < up; ++i) {
			map[i][c-1] = map[i+1][c-1];
		}
		for (int i = c - 1; i > 1; i--) {
			map[up][i] = map[up][i - 1];
		}
		map[up][1] = 0;

		for (int i = down +1; i <r ; ++i) {
			map[i][0] = map[i+1][0];
		}
		for (int i = 0; i < c; ++i) {
			map[r-1][i] = map[r-1][i + 1];
		}
		for (int i = r-1; i > down ; --i) {
			map[i][c - 1] = map[i - 1][c - 1];
		}
		for (int i = c - 1; i > 1; i--) {
			map[down][i] = map[down][i - 1];
		}
		map[down][1] = 0;
	}
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != -1 && map[i][j] != 0) {
				sum += map[i][j];
			}
		}
	}
	cout << sum;
}
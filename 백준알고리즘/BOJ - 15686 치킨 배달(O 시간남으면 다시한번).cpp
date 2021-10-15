//치킨 배달 - 시간 복잡도를 줄여보자
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int map[51][51];
int dark;
int res;
void copy(int temp[51][51], int ori[51][51]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp[i][j] = ori[i][j];
		}
	}
}
void check() {
	int dist = 0;
	int dist_min = 1000000;
	int dosi_dist = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (map[i][j] == 1) {
				dist_min = 1000000;
				for (int y = 1; y <= n; y++) {
					for (int x = 1; x <= n; x++) {
						if (map[y][x] == 2) {
							dist = abs(y - i) + abs(x - j);
							if (dist_min > dist) dist_min = dist;
						}
					}
				}
				dosi_dist += dist_min;
			}
		}
	}
	if (res > dosi_dist) res = dosi_dist;
}

void dfs(int d_num, int sx, int sy) {
	if (d_num <= m) {
		check();
		return;
	}
	for (int y = sy; y <= n; y++) {
		for (int x = sx; x <= n; x++) {
			if (map[y][x] == 2) {
				map[y][x] = 0;
				dfs(d_num - 1,x, y);
				map[y][x] = 2;
			}
			sx = 0;
		}
	}
}


int main() {
	cin >> n >> m;
	dark = 0;
	res = 99999999;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				dark++;
			}
		}
	}
	dfs(dark, 1, 1);
	cout << res;
}
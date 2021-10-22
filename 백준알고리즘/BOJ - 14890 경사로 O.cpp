// 경사로 조건파악 ㅠㅠ
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[101][101];
int n, l;
//0이 아래 1이 오른쪽
int dirx[2] = { 0,1 };
int diry[2] = { 1,0 };

bool check(int i, int dir) {
	bool res = true;
	if (dir == 0) {
		bool gradi[101] = { false };
		for (int y = 1; y < n; y++) {
		if (map[y][i] != map[y+1][i]) {

				if (abs(map[y][i] - map[y + 1][i]) > 1) return false;

				if (map[y][i] > map[y + 1][i]) {
					for (int j = y + 1; j < y + l; j++) {
						if ((j > n)) return false;
						if (gradi[j]) return false;
						if (gradi[j + 1]) return false;
						if (map[j][i] != map[j+1][i]) {
							res = false;
							return res;
						}
						gradi[j] = true;
					}
					gradi[y + l] = true;
					y = y + l -1;
				}
				else {
					if (y - l +1 <= 0) return false;
					if (l == 1 && gradi[y] == true) return false;
					for (int j = y -l +1; j < y; ++j) {
						if (gradi[j]) return false;
						if (gradi[j + 1]) return false;
						if (map[j][i] != map[j+1][i]) {
							res = false;
							return res;
						}
						gradi[j] = true;
					}
					gradi[y] = true;
				}
			}
		}
	}
	else {
		bool gradi[101] = { false };
		for (int x = 1; x < n; x++) {
			
			if (map[i][x] != map[i][x+1]) {

				if (abs(map[i][x] - map[i][x+1]) > 1) return false;

				if (map[i][x] > map[i][x+1]) {
					for (int j = x + 1; j < x + l; j++) {
						if ((j > n)) return false;
						if (gradi[j]) return false;
						if (gradi[j + 1]) return false;
						if (map[i][j] != map[i][j + 1]) {
							res = false;
							return res;
						}
						gradi[j] = true;
					}
					gradi[x + l] = true;
					x = x + l - 1;
				}
				else {
					if (x - l +1 <= 0) return false;
					if (l == 1 && gradi[x] == true) return false;
					for (int j = x - l + 1; j < x; ++j) {
						if (gradi[j]) return false;
						if (gradi[j + 1]) return false;
						if (map[i][j] != map[i][j+1]) {
							res = false;
							return res;
						}
						gradi[j] = true;
					}
					gradi[x ] = true;
				}
			}
		}
	}
	return res;
}

int main() {
	cin >> n; cin >> l;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (check(i, j)) cnt++;
		}
	}
	cout << cnt;
}
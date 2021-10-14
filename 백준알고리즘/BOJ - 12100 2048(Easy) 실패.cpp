//삼성 코딩테스트 2048 답지보고 배낌 다시 풀어볼것

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int result;

struct BOARD {
	int map[20][20];

	void rotate() {
		int temp[20][20];

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; ++x) {
				temp[y][x] = map[n - x - 1][y];
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; ++x) {
				map[y][x] = temp[y][x];
			}
		}
	}

	int get_max() {
		int ret = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; ++x) {
				if (ret < map[y][x]) {
					ret = map[y][x];
				}
			}
		}
		return ret;
	}

	void up() {
		int temp[20][20];

		for (int x = 0; x < n; ++x) {
			int index = -1, flag = 0;
			for (int y = 0; y < n; ++y) {
				if (map[y][x] == 0) continue;
				if (flag == 1 && map[y][x] == temp[index][x]) {
					temp[index][x] *= 2;
					flag = 0;
				}
				else {
					temp[++index][x] = map[y][x];
					flag = 1;
				}
			}
			for (++index; index < n; ++index) {
				temp[index][x] = 0;
			}
		}
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; ++x) {
				map[y][x] = temp[y][x];
			}
		}
	}

};



void dfs(BOARD cur, int cnt) {
	if (cnt == 5) {
		int max = cur.get_max();
		if (result < max) {
			result = max;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		BOARD next = cur;
		next.up();
		dfs(next, cnt + 1);
		cur.rotate();
	}
}

int main() {
	cin >> n;
	BOARD start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> start.map[i][j];
		}
	}
	result = 0;
	dfs(start, 0);
	cout << result;
	return 0;
}

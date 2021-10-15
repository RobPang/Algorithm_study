//check하는 알고리즘을 좀더 잘 떠올리고 빡구현 잘하고 연결관계 배열 크기 잘 생각하고
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m ,h;
int map[31][11];
int res;

bool check() {
	bool res = true;
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][pos] == 1) {
				pos++;
			}
			else if (map[j][pos-1] == 1) {
				pos--;
			}
		}
		if (pos != i) {
			res = false;
			return res;
		}
	}
	return res;
}

void dfs(int cnt, int x, int y) {
	if (cnt > res) return;
	if (check()) {
		if (res > cnt) res = cnt;
	}
	if (cnt == 3) return;

	for (int i = y; i <= h; i++) {
		for (int j = x; j < n; j++) {
			if (map[i][j - 1] ==  0 && map[i][j] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;
				dfs(cnt + 1, j, i);
				map[i][j] = 0;
			}
		}
		x = 1;
	}

}

int main() {
	cin >> n >> m >> h;
	
	for (int i = 0; i < m; i++) {
		int y;
		int x;
		cin >> y >> x;
		map[y][x] = 1;
	}
	res = 4;

	dfs(0,1,1);

	if (res == 4) {
		res = -1;
	}
	cout << res << '\n';
}

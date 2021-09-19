//음식물 피하기 - DFS 기본
#include <iostream>

using namespace std;

int xdir[4] = { 0, 1, 0 , -1 };
int ydir[4] = { 1, 0, -1, 0 };
int map[101][101];
bool check[101][101];
int n, m;
int cnt;
int result;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void dfs(int x, int y) {
	if(!(y > 0 && y > 0 && x <= n && y <= m && map[x][y] == 1)) return;
	cnt++;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int dx = x + xdir[i];
		int dy = y + ydir[i];
		if (dy <= 0 || dy <= 0 || dx > n || dy > m) continue;
		if (!(check[dx][dy]) && map[dx][dy] == 1) {
			check[dx][dy] = true;
			dfs(dx, dy);
		}
	}

}


int main() {
	int c;
	cin >> n >> m >> c;

	for (int i = 0; i < c; i++) {
		int a, b;

		cin >> a >> b;
		map[a][b] = 1;
	}

	result = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!(check[i][j]) && map[i][j] == 1) {
				cnt = 0;
				dfs(i, j);
				result = max(result, cnt);
			}
		}
	}

	cout << result;

}
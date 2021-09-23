//점프 - dp 문제
#include <iostream>

using namespace std;

long long dp[101][101];
int map[101][101];
bool check[101][101];
int Max(int a, int b) { return (a > b) ? a : b; }

int n;
int cnt;

//시간 초과
void dfs(int x, int y) {
//	cout << x << ','<< y  << map[x][y] << '\n';
	if (x == n && y == n) {
		cnt++;
		return;
	}
	if (map[x][y] == 0) return;

	int dx = x + map[x][y];
	int dy = y + map[x][y];
	if (dx <= n) {
		dfs(dx, y);
	}
	if (dy <= n) {
		dfs(x, dy);
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	dp[1][1] = 1;
	check[1][1] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!check[i][j]) continue;
			int temp = map[i][j];
			if (temp == 0) continue;
			if (i + temp <= n) {
				check[i + temp][j] = true;
				dp[i + temp][j] += dp[i][j];
			}
			if (j + temp <= n) {
				check[i][j+temp] = true;
				dp[i][j + temp] += dp[i][j];
			}
		}
	}
//	dfs(1, 1);

	cout << dp[n][n];
}
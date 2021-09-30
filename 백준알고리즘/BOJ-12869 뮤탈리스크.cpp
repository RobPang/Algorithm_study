// 뮤탈리스크 - dfs나 bfs와 비슷함 근데 여기서 dp를 추가
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int scv[4];
int dp[61][61][61];

int dfs(int f, int s, int t) {
	if (f < 0) return dfs(0, s, t);
	if (s < 0) return dfs(f, 0, t);
	if (t < 0) return dfs(f, s, 0);

	if (f == 0 && s == 0 && t == 0) {
		return 0; 
	}

	int& res = dp[f][s][t];

	if (res != -1) {
		return res;
	}

	res = 999999;
	res = min(res, dfs(f - 9, s - 3, t - 1)+1);
	res = min(res, dfs(f - 9, s - 1, t - 3)+1);
	res = min(res, dfs(f - 3, s - 1, t - 9)+1);
	res = min(res, dfs(f - 3, s - 9, t - 1)+1);
	res = min(res, dfs(f - 1, s - 3, t - 9)+1);
	res = min(res, dfs(f - 1, s - 9, t - 3)+1);

	return res;
}


int main() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> scv[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(scv[1], scv[2], scv[3]) << '\n';

}
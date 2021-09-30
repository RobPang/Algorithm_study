//행렬 곱셈 순서 - dp 각각을 분리
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int r[501];
int c[501];
long long dp[501][501];

long long dfs(int a, int b) {
	if (b - a == 1) {
		int temp = r[a] * c[a] * c[b];
	}
	if (a == b) return 0;
	long long& res = dp[a][b];

	if (res != -1) {
		return res;
	}
	res = 9999999999;
	for (int i = a; i <= b-1; i++) {
		res = min(res, dfs(a, i) + dfs(i+1, b) + r[a]*c[i]*c[b]);
	}

	return res;
}


int main() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> c[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(1,n) << '\n';

}
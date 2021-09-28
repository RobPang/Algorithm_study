//평범한 배낭 - 무게와 가치 두가지 정보
#include <iostream>
#include <algorithm>

using namespace std;

int w[102];
int v[102];
long long dp[102][100002];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k];
}

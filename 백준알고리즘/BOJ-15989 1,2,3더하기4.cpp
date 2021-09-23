//1,2,3 더하기 4 - dp프라블럼
#include <iostream>

using namespace std;

int dp[10001][4];
int num[10001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	dp[1][1] = dp[2][1] = dp[3][1] = dp[2][2] = dp[3][3] = dp[3][2] = 1;
	for (int i = 4; i <= 10000; i++) {
		dp[i][1] += dp[i - 1][1];
		dp[i][2] = dp[i-2][1] + dp[i - 2][2];
		dp[i][3] = dp[i-3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
	for (int i = 1; i <= n; i++) {
		cout << dp[num[i]][1] + dp[num[i]][2] + dp[num[i]][3] << '\n';
	}
}
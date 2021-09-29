// 소형기관차 - 열차 한개, 두개, 3개 각각 최대 for문 1~3 후 각 시작점~n까지
#include <iostream>
#include <algorithm>

using namespace std;

int dp[50001][4];
int sum[50001];
int n, m;

int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}
	cin >> m;

	//memset(dp, 0, sizeof(dp));
	for (int j = 1; j <= 3; j++) {
		for (int i = j*m; i <= n; i++) {
			if (j == 1) dp[i][j] = max(dp[i - 1][j], sum[i] - sum[i - m]);
			else {
				dp[i][j] = max(dp[i - m][j - 1] + sum[i] - sum[i - m], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n][3];
}
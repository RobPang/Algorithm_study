//데스노트 - 여러 조건 신경 써야됨, 여러 정보 같이 전달
#include <iostream>
#include <algorithm>

using namespace std;

int num[1001];
long long dp[1001][1001];
bool check[1001][1001];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	int result = 1e9;
	check[1][num[1]] = true;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 1000; k >= 0; --k) {
				if (check[i - j][k]) {
					int temp = k + num[i] + 1;
					if (temp <= m) {
						if (check[i - j][temp]) {
							dp[i - j][temp] = min(dp[i - j][k], dp[i - j][temp]);
						}
						else {
							dp[i - j][temp] = dp[i - j][k];
							check[i - j][temp] = true;
						}
					}
					if (dp[i - j + 1][num[i]] != 0) {
						dp[i - j + 1][num[i]] = min(dp[i - j][k] + (m - k)*(m - k), dp[i - j + 1][num[i]]);
					}
					else {
						dp[i - j + 1][num[i]] = dp[i - j][k] + (m - k)*(m - k);
					}
					check[i - j + 1][num[i]] = true;
					check[i - j][k] = false;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (check[i][k]) {
				cout << dp[i][k];
				return 0;
			}
		}
	}

}
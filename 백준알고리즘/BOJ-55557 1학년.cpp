//1학년 - DP 두가지 정보 
#include <iostream>
#include <algorithm>

using namespace std;

long long dp[101][21];
int num[101];

int main() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	dp[1][num[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i-1][j] != 0) {
				if (j + num[i] <= 20) {
					dp[i][j + num[i]] += dp[i - 1][j];
				}
				if (j - num[i] >= 0) {
					dp[i][j - num[i]] += dp[i - 1][j];
				}
			}

		}
			
			
	}
	cout << dp[n - 1][num[n]];
}
// 괄호 - 수학, dp 점화식 만들기가 너무 어렵다
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[5001];
int num[101];

int main() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= 5000; i++) {
		if (i % 2 == 1) continue;
		for (int j = 2; j <= i; j += 2)
		{
			dp[i] += dp[j - 2] * dp[i - j];
			dp[i] = dp[i] % 1000000007;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[num[i]] <<'\n';
	}
}
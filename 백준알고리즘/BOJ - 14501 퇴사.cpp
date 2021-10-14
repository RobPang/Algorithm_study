//퇴사 - dp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[21];
int t[17];
int p[17];
int n;

int bigger(int a, int b) { if (a > b) return a; return b; }

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		cin >> p[i];
	}
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		dp[i + 1] = max(dp[i], dp[i + 1]);
		dp[i+t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
	}
	cout << dp[n+1];
}

#include <iostream>

using namespace std;
int ti[1500001];
int pi[1500001];
int dp[1500001];

int Max(int a, int b) { return (a > b) ? a : b; }

int main() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> ti[i] >> pi[i];
	}
	int max = 0;
	for (int i = 1; i <= n+1; i++) {
		max = Max(max, dp[i]);
		if (i + ti[i] > n +1) continue;
		dp[i + ti[i]] = Max(max + pi[i], dp[i + ti[i]]);
	}
	cout << max;
}
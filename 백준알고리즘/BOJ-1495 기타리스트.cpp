//기타리스트 - dp 이중배열을 사용한 dp
#include <iostream>

using namespace std;

bool dp[101][1001];
int vol[1001];

int bigger(int a, int b) { if (a > b) return a; return b; }

int main() {
	int n, s, m;
	cin >> n >> s >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> vol[i];
	}

	dp[0][s] = true;
	//vol[0] = s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i-1][j]) {
				int x = j + vol[i];
				int y = j - vol[i];
				if (x <= m) dp[i][x] = true;
				if (y >= 0) dp[i][y] = true;
			}
		}
	}
	int max = 0;
	for (int j = m; j >= 0; j--) {
		if(dp[n][j]) {
			cout << j;
			return 0;
		}
	}
	cout << -1;
}
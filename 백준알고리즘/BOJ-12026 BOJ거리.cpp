//BOJ 거리 - DP 문제 경우별로 나눠서 풀기
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int str[1001];
long long dp[1001];
bool check[1001];

int main() {
	int n; 	cin >> n;
	string temp;
		cin >> temp;
	for (int j = 1; j <= temp.length(); j++) {
		str[j] = temp[j-1];
	}
	fill(dp, dp + 1001, 1e9);
	dp[1] = 0;
	check[1] = true;
	
	char cur = 'B';
	char next = 'O';
	for (int i = 2; i <= n; i++) {
		if (str[i] == 'O') {
			for (int j = i-1; j >= 1; j--) {
				if (check[j] && str[j] == 'B') {
					dp[i] = min(dp[i],dp[j] + (i - j)*(i - j));
					check[i] = true;
				}
			}
		}
		else if (str[i] == 'J') {
			for (int j = i - 1; j >= 1; j--) {
				if (check[j] && str[j] == 'O') {
					dp[i] = min(dp[i], dp[j] + (i - j)*(i - j));
					check[i] = true;
				}
			}
		}
		else if (str[i] == 'B') {
			for (int j = i - 1; j >= 1; j--) {
				if (check[j] && str[j] == 'J') {
					dp[i] = min(dp[i], dp[j] + (i - j)*(i - j));
					check[i] = true;
				}
			}
		}
	}
	if (dp[n] > 1000000) {
		cout << -1;
	}
	else {
		cout << dp[n];
	}
	
}
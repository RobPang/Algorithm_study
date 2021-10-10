//acka - 노래선택 재풀이 필요

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


long long dp[51][51][51][51];

long long dfs(int s, int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	
	if (s == 0) {
		if (a == 0 && b == 0 && c == 0) {
			return 1;
		}
		else return 0;
	}

	long long& res = dp[s][a][b][c];

	if (res != -1) {
		return res;
	}
	
	res = 0;
	res += dfs(s - 1, a - 1, b, c);
	res += dfs(s - 1, a - 1, b-1, c);
	res += dfs(s - 1, a - 1, b-1, c-1);
	res += dfs(s - 1, a, b-1, c);
	res += dfs(s - 1, a , b - 1, c - 1);
	res += dfs(s - 1, a - 1, b, c - 1);
	res += dfs(s - 1, a , b, c - 1);
	res %= 1000000007;
	return res;
}


int main() {
	int n; cin >> n;
	int a, b, c;
	
	cin >> a >> b >> c;
	

	memset(dp, -1, sizeof(dp));

	cout << dfs(n,a,b,c) << '\n';

}
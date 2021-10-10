//출근 기록 - 그전 2개만 기억

#include <iostream>
#include <string>

using namespace std;

int S;
bool dp[51][51][51][3][3] = { false,  };
char result[51];
int A, B, C;


bool dfs(int a, int b, int c, int bbefore, int before) {
	if (a == A && b == B && c == C) {
		return true;
	}


	if(dp[a][b][c][bbefore][before]) {
		return false;
	}
	dp[a][b][c][bbefore][before] = true;

	if (a + 1 <= A) {
		result[a + b + c] = 'A';
		if (dfs(a + 1, b, c, before, 0)) {
			return true;
		}
	}
	if (b + 1 <= B) {
		result[a + b + c] = 'B';
		if (before != 1 && dfs(a, b+1, c, before, 1)) {
			return true;
		}
	}
	if (c + 1 <= C) {
		result[a + b + c] = 'C';
		if (before != 2 && bbefore != 2 && dfs(a, b, c+1, before, 2)) {
			return true;
		}
	}
	return false;

}


int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A') A++;
		else if (str[i] == 'B') B++;
		else C++;
	}
	if (dfs(0, 0, 0, -1, -1)) {
		for (int i = 0; i < str.size(); i++) {
			cout << result[i];
		}
	}
	else cout << -1;
	cout << '\n';
	return 0;
}


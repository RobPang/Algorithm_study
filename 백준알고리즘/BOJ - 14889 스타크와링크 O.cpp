// 스타크와 링크 - 조합뽑을때의 범위 설정이 중요
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int s[21][21];
int n;
int people[21];
int ret;

void dfs(int num, int start) {
	if (n/2 == num) {
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 1; i < n; i++) {
			if (people[i] == 1) {
				for (int j = i+1; j <= n; j++) {
					if (people[j] == 1) {
						sum1 += (s[i][j] + s[j][i]);
					}
				}
			}
			else {
				for (int j = i+1; j <= n; j++) {
					if (people[j] == 0) {
						sum2 += (s[i][j] + s[j][i]);
					}
				}
			}
		}
		if (ret > abs(sum1 - sum2)) ret = abs(sum1 - sum2);
		return;
	}
	for (int i = start; i <= n/2 + num; i++) {
		people[i] = 1;
		dfs(num + 1, i+1);
		people[i] = 0;
	}
}

int main() {
	cin >> n;
	memset(people, 0, sizeof(people));
	memset(s, 0, sizeof(s));
	ret = 1000000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	dfs(0, 1);
	cout << ret << '\n';
}
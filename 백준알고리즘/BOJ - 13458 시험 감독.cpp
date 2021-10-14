// 시험감독 간단한 수학...
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int room[1000001];
int dp[1000001];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d",&room[i]);
	}
	int b, c;
	cin >> b >> c;

	long long num = n;


	for (int i = 0; i < n; i++) {
		int temp = room[i];
		int cnt = 0;
		temp = temp - b;
		if (temp <= 0) continue;
		int mok = temp / c;
		int na = temp % c;
		if (na == 0) {
			num += mok;
		}
		else {
			num += (mok + 1);
		}
	}
	cout << num;

}
//동전1 - 동적 프로그래밍 (기존에 한 계산 저장)
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int arr[101];
	int dp[10001] = { 0 };

    scanf("%d %d", &n, &k); //cin으로 하면 틀리고 scanf는 맞았다 무슨이율까? 시간문젠가? 도통모르겠다

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
        if(arr[i] > k) continue;

		for (int j = arr[i]; j <= k; j++) {
				dp[j] += dp[j - arr[i]];
		}
	}

	printf("%d\n", dp[k]);

	
}

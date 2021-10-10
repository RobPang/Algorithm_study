// 팰린드롬 - dfs쪽이 문제인줄 알았는데 printf를 cout으로 하여 시간 초과였음 시간 관련문제들은 전부 printf로 바꾼후 시도

// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// int arr[2001];
// int s[1000001];
// int e[1000001];
// int dp[2001][2001];
// bool check[2001][2001];

// //bool dfs(int start, int end) {
// //	if (start > end) return false;
// //	if (check[start][end]) return dp[start][end];
// //	check[start][end] = true;
// //	if (start == end) {
// //		dp[start][end] = true;
// //		return true;
// //	}
// //	if(start + 1 == end) {
// //		if (arr[start] == arr[end]) {
// //			dp[start][end] = true;
// //			return true;
// //		}
// //		else {
// //			dp[start][end] = false;
// //			return false;
// //		}
// //	}
// //
// //	if (arr[start] == arr[end]) {
// //		if (dfs(start + 1, end - 1)) {
// //			dp[start][end] = true;
// //			return true;
// //		}
// //		else {
// //			dp[start][end] = false;
// //			return false;
// //		}
// //	}
// //	else {
// //		dp[start][end] = false;
// //		return false;
// //	}
// //
// //	return false;
// //}

// int main() {
// 	int n; cin >> n;
// 	memset(dp, 0, sizeof(dp));
// 	for (int i = 1; i <= n; i++) {
// 		scanf("%d", &arr[i]);
// 	}

// 	int a; cin >> a;

// 	for (int start = 1; start <= n; start++) {
// 			dp[start][start] = 1;
// 			if (arr[start - 1] == arr[start]) {
// 				dp[start - 1][start] = 1;
// 			}
// 	}
	
// 	for (int gap = 2; gap < n; gap++) {
// 		for (int start = 1; start + gap <= n; start++) {
// 			int end = start + gap;
// 			if (arr[start] == arr[end] && dp[start + 1][end - 1]) {
// 				dp[start][end] = 1;
// 			}
// 		}
// 	}
	


// 	//for (int i = 1; i <= a; i++) {
// 	//	cin >> s[i];
// 	//	cin >> e[i];
// 	//	if (dp[s[i]][e[i]]) {
// 	//		cout << 1 << '\n';
// 	//	}
// 	//	else {
// 	//		cout << 0 << '\n';
// 	//	}
// 	//}

// 		for (int i = 1; i <= a; i++) {
// 			int s, e;
// 			scanf("%d", &s);
// 			scanf("%d", &e);
// 			printf("%d\n", dp[s][e]);
// 		}


// 	return 0;
// }


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[2001];
int s[1000001];
int e[1000001];
bool dp[2001][2001];
bool check[2001][2001];

bool dfs(int start, int end) {
	if (start > end) return false;
	if (check[start][end]) return dp[start][end];
	check[start][end] = true;
	if (start == end) {
		dp[start][end] = true;
		return true;
	}
	if (start + 1 == end) {
		if (arr[start] == arr[end]) {
			dp[start][end] = true;
			return true;
		}
		else {
			dp[start][end] = false;
			return false;
		}
	}

	if (arr[start] == arr[end]) {
		if (dfs(start + 1, end - 1)) {
			dp[start][end] = true;
			return true;
		}
		else {
			dp[start][end] = false;
			return false;
		}
	}
	else {
		dp[start][end] = false;
		return false;
	}

	return false;
}

int main() {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int a; cin >> a;




	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dfs(i, j);
		}

	}

	for (int i = 1; i <= a; i++) {
		int s, e;
		scanf("%d", &s);
		scanf("%d", &e);
		if (dp[s][e]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
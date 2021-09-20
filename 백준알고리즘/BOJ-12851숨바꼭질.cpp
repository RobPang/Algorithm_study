//숨바꼭질 dfs bfs
#include <iostream>
#include  <queue>

using namespace std;

//int cnt[1000000001];
bool check[100010];
int result;
int cnt;
int dfs_cnt;

//pair를 통한 cnt 증가 , 여러번 카운트할때 도착지점도 check를 해버리면 한번만 도착함
void bfs(int start, int end) {
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	check[start] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int count = q.front().second;
		q.pop();
		check[x] = true;

	//	cout << x << ' ';
		if (x == end) {
			if (cnt == 0) {
				result = count;
				cnt = 1;
			}
			else if (result == count) {
				cnt++;
			}
		}
		for (int i = 0; i < 3; i++) {
		//	if (check[x]) continue;
			if (i == 0) {
				int y = x * 2;
				if (y > 100000) continue;
				if (x <= end && !check[y]) {
					q.push(make_pair(y, count + 1));
				}
			}
			else if (i == 1) {
				int y = x + 1;
				if (y > end) continue;
				if (!check[y]) {
					q.push(make_pair(y, count + 1));
				}
			}
			else {
				int y = x - 1;
				if (y < 0) continue;
				if (!check[y]) {
					q.push(make_pair(y, count + 1));
				}
			}
			check[end] = false;
		}
	}

}
//시간 초과
void dfs(int start, int end, int sec) {
	
	if (result < sec) return;
	check[start] = true;
//	cout <<  start <<'(' << sec <<')'<< ' ';
	if (start == end) {
		if (cnt == 0) {
			//check[end] = false;
			result = sec;
			cnt = 1;
		}
		else if (result == sec) {
			//check[end] = false;
			cnt++;
		}
		
	}
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			int y = start * 2;
			if (y > 100000) continue;
			if (start < end && !check[y]) {
				dfs(y, end, sec+1);
				check[y] = false;
		//		cout << '\n';

			}
		}
		else if (i == 1) {
			int y = start + 1;
			if (y > end) continue;
			if (!check[y]) {
				dfs(y, end, sec+1);
				check[y] = false;
		//		cout << '\n';

			}
		}
		else {
			int y = start - 1;
			if (y < 0) continue;
			if (!check[y]) {
				dfs(y, end, sec+1);
				check[y] = false;
			//	cout << '\n';

			}
		}
	}
}


int main() {
	long long  n, k; cin >> n >> k;
	result = 99999;
	cnt = 0;
	bfs(n, k);
	//dfs(n, k, 0);
	if (result == 99999) {
		result = -1;
	}
	cout << result << '\n' << cnt;

}
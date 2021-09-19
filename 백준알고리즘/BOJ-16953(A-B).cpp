//A->B BFS greed
#include <iostream>
#include  <queue>

using namespace std;

//int cnt[1000000001];

int result;
int cnt;

//pair를 통한 cnt 증가 
void bfs(long long start, long long end) {
	queue<pair<int,int>> q;
	q.push(make_pair(start,1));
	while (!q.empty()) {
		long long x = q.front().first;
		int count = q.front().second;
		q.pop();
		if (x == end) {
			result = count;
		}
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				long long y = x * 10 + 1;
				if (y <= end) {
					q.push(make_pair(y,count+1));
				}
			}
			else {
				int y = x * 2;
					cnt++;
				if (y <= end) {
					q.push(make_pair(y, count + 1));
				}
			}
		}
	}

}

void dfs(long long start, long long end) {
	if (start > end) return;
	cnt++;
	if (start == end) {
		result = (result < cnt) ? result : cnt;
		return;
	}
	
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			long long y = start * 10 + 1;
			if (y <= end) {
				dfs(y, end);
				cnt--;
			}
		}
		else {
			int y = start * 2;
			
			if (y <= end){
				dfs(y, end);
				cnt--;
			}
		}
	}
}


int main() {
	long long  n, k; cin >> n >> k;
	result = 99999;
	bfs(n, k);
	if (result == 99999) {
		result = -1;
	}
	cout << result;

}
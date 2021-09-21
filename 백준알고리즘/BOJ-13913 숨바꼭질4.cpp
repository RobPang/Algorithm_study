//숨바꼭질4 - bfs & DP
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[200001];
int DP[200001];

int bfs_cnt;

void bfs(int start, int end) {
	queue<pair<int, int>> q;

	q.push({ start,0 });
	check[start] = true;
	while (!q.empty()) {
		int  cur = q.front().first;
		int count = q.front().second;
		q.pop();
		if (cur == end) {
			cout << count << '\n';
			bfs_cnt = count;
			break;
		}

		int next = cur * 2;
		if (next < 200000 && !check[next]) {
			check[next] = true;
			q.push({ next,count + 1 });
			DP[next] = cur;
		}
		next = cur + 1;
		if (next <= end && !check[next]) {
			check[next] = true;
			q.push({ next,count + 1 });
			DP[next] = cur;
		}
		next = cur - 1;
		if (next >= 0 && !check[next]) {
			check[next] = true;
			q.push({ next,count + 1 });
			DP[next] = cur;
		}
	}

}
int main() {
	int n, k;
	cin >> n >> k;

	bfs(n, k);
	vector<int> v;
	int temp = DP[k];
	v.push_back(k);
	for (int i = 0; i < bfs_cnt; i++) {
		v.push_back(temp);
		temp = DP[temp];
	}
	for (int i = 0; i < bfs_cnt + 1; i++) {
		int x = v.back();
		v.pop_back();
		cout << x << ' ';
	}
}


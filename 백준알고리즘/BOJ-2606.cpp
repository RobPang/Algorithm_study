//boj2606 바이러스 bfs
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[101];
bool check[101];
int n;
int cnt;
void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!check[y]) {
				cnt++;
				check[y] = true;
				q.push(y);
			}

		}
	}


}


int main() {
	int k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cnt = 0;
	bfs(1);
	cout << cnt;


}

//미로 탐색 - 최단거리 BFS DFS는 시간 초과 조심
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int xdir[4] = { 0, 1, 0 , -1 };
int ydir[4] = { 1, 0, -1, 0 };
int n, k;

int map[101][101];
bool ch[101][101];

int result;
int Cnt[101][101];

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
//DFS 시간 초과
void DFS(int x, int y, int cnt) {
	if (!(x >= 0 && y >= 0 && x < n && y < k && map[x][y] == 1)) return;
	ch[x][y] = true;
	if (x == n - 1 && y == k - 1) {
	//	cout << 'a';
		result = min(result, cnt);
		ch[x][y] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int dx = x + xdir[i];
		int dy = y + ydir[i];
		if (dx < 0 || dy < 0) continue;
		if ((!ch[dx][dy])&&map[dx][dy] == 1) {
			DFS(x + xdir[i], y + ydir[i], cnt + 1);
			ch[dx][dy] = false;
		}
	}
}

void bfs(int x, int y) {
	ch[x][y] = true;
	Cnt[x][y] = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++ ) {
			int dx = x + xdir[i];
			int dy = y + ydir[i];
			if (dx < 0 || dy < 0 || x >= n || y >= k) continue;
			if ((!ch[dx][dy]) && map[dx][dy] == 1) {
				ch[dx][dy] = true;
				Cnt[dx][dy] = Cnt[x][y] + 1;
				q.push(make_pair(dx, dy));
				
			}

		}

	}

}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%1d", &map[i][j]) ;
		}
	}
	//result = 1000000;
	//DFS(0, 0, 1);
	bfs(0, 0);
	cout << Cnt[n-1][k-1];


}
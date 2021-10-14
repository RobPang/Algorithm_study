//dfs로 조합 뽑는법 잘 생각하자
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int map[9][9];
//bool check[9][9];

int dirx[4] = { 1,-1,0,0 };
int diry[4] = { 0 , 0, 1, -1 };
int ret;

void bfs() {
	int  backup[9][9];
	queue<pair<int, int> > q;
	bool check[9][9] = { false };
	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= m; ++x) {
			backup[y][x] = map[y][x];
			if (backup[y][x] == 2) {
				q.push({ y,x });
				check[y][x] = 1;
			}
		}
	}

	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		backup[y][x] = 2;
		for (int i = 0; i < 4; i++) {
			int ny = y + diry[i];
			int nx = x + dirx[i];
			if (!(nx >= 1 && ny >= 1 && ny <= n && nx <= m)) continue;
			if (check[ny][nx]) continue;
			if (backup[ny][nx] == 0) {
				check[ny][nx] = true;
				q.push({ ny,nx });
			}

		}
	}
	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= m; ++x) {
			if (backup[y][x] == 0) {
				++cnt;
			}
		}
	}
	if (ret < cnt) ret = cnt;
}

void pick_dfs(int cnt, int sy, int sx) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int y = sy; y <= n; ++y) {
		for (int x = sx; x <= m; ++x) {
			if (map[y][x] == 0) {
				map[y][x] = 1;
				pick_dfs(cnt + 1, y, x);
				map[y][x] = 0;
			}
			sx = 1;
		}
	}
}

int main() {
	cin >> n >> m;
		
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

//	int result = 0;
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		if (map[i][j] == 0) {
	//			map[i][j] = 1;
	//			for (int y = i; y <= n; y++) {
	//				for (int x = j; x <= n; x++) {
	//					if (map[y][x] == 0) {
	//						map[y][x] = 1;
	//						for (int a = y; a <= n; a++) {
	//							for (int b = x; b <= n; b++) {
	//								if (map[a][b] != 0) {
	//									map[a][b] = 1;
	//									bfs();
	//									/*int temp = bfs();
	//									if (result < temp) {
	//										result = temp;
	//									}*/
	//									map[a][b] = 0;
	//								}
	//							}
	//							
	//						}
	//						map[y][x] = 0;
	//					}

	//				}
	//			}
	//			map[i][j] = 0;
	//		}
	//	}
	//}
	pick_dfs(0, 1, 1);
	cout << ret;
}

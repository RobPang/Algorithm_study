//BOJ - 21609 상어 중학교  RRIORQUEUE사용해보실?
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[20][20];
bool check[20][20];

int dirx[4] = { 0, 1, 0, -1 };
int diry[4] = { 1, 0, -1, 0 };

struct pos
{
	int x, y;
};

queue<pos> cur_q;
queue<pos> pop_q;
int Max;
int res;
int gx, gy;

void bfs(int y, int x) {
	queue<pos> q;
	queue<pos> dummy;
	q.push({ x,y });
	bool ncheck[20][20] = { false, };
	check[y][x] = true;
	ncheck[y][x] = true;
	int color = map[y][x];
	int cnt = 0;

	int candi_y = n;
	int candi_x = n;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		dummy.push(q.front());
		q.pop();
		cnt++;
		if (map[cy][cx] != 0) {
			if (candi_y > y) {
				candi_y = y;
				candi_x = x;
			}
			else if (candi_y == y) {
				if (candi_x > x) candi_x = x;
			}
		}
		for (int i = 0; i < n; i++) {
			int ny = cy + diry[i];
			int nx = cx + dirx[i];
			if (!(ny >= 0 && nx >= 0 && nx < n && ny < n)) continue;
			if (ncheck[ny][nx]) continue;
			if (map[ny][nx] == color) {
				ncheck[ny][nx] = true;
				check[ny][nx] = true;
				q.push({ nx,ny });
			}
			else if (map[ny][nx] == 0) {
				ncheck[ny][nx] = true;
				q.push({ nx,ny });
			}
		}
	}
	if (cnt < 2) return;
	if (Max < cnt) {
		Max = cnt;
		while (!pop_q.empty()) {
			pop_q.pop();
		}
		while (!dummy.empty()) {
			pop_q.push(dummy.front());
			dummy.pop();
		}
	}
	else if (Max == cnt) {
		if (gy < candi_y) {
			gy = candi_y;
			gx = candi_x;
			while (!pop_q.empty()) {
				pop_q.pop();
			}
			while (!dummy.empty()) {
				pop_q.push(dummy.front());
				dummy.pop();
			}
		}
		else if (gy == candi_y) {
			if (gx < candi_x) {
				gx = candi_x;
				while (!pop_q.empty()) {
					pop_q.pop();
				}
				while (!dummy.empty()) {
					pop_q.push(dummy.front());
					dummy.pop();
				}
			}
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}	
	}
//	int flag = 1;
	int res = 0;
	while (1) {
		int flag = 0;
		Max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false;
			}
		}
		gx = 0; gy = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j]) continue;
				if (map[i][j] == 0 || map[i][j] == 6 || map[i][j] == -1) continue;
				bfs(i, j);
			}
		}
		res += pop_q.size() * pop_q.size();
		while (!pop_q.empty()) {
			flag = 1;
			int y = pop_q.front().y;
			int x = pop_q.front().x;
			pop_q.pop();
			map[y][x] = 6;
		}
		if (flag == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; --j) {
				if (map[j][i] != -1 && map[j][i] != 6) {
					int temp = map[j][i];
					int idx = j;
					for (int y = j+1; y < n; y++) {
						
						if (map[y][i] == 6) {
							if (y == n - 1) {
								idx = n - 1;
							}
							continue;
						}
						else {
							idx = y - 1;
							break;
						}
						
					}
					map[j][i] = 6;
					map[idx][i] = temp;
				}
			}
		}

		int temp[20][20] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = map[j][n - 1 - i];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = temp[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; --j) {
				if (map[j][i] != -1 && map[j][i] != 6) {
					int temp = map[j][i];
					int idx = j;
					for (int y = j + 1; y < n; y++) {

						if (map[y][i] == 6) {
							if (y == n - 1) {
								idx = n - 1;
							}
							continue;
						}
						else {
							idx = y - 1;
							break;
						}

					}
					map[j][i] = 6;
					map[idx][i] = temp;
				}
			}
		}
		int a = map[0][0];
	}
	cout << res;
}
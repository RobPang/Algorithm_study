//구글 옮기기 struct를 사용한 queue

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;


char map[11][11];
bool check[11][11][11][11];


int xdir[4] = { 0,1,0,-1 };
int ydir[4] = { -1,0,1,0 };

struct INFO {
	int rx, ry, bx, by, count;
};
INFO start;
int n, m;
int cnt;

void bfs() {
	queue<INFO> q;
	q.push(start);
	check[start.ry][start.rx][start.by][start.bx] = true;
	cnt = -1;
	while (!q.empty()) {
		INFO curret = q.front();
		q.pop();
		if (curret.count > 10) break;
		int bx = curret.bx;
		int by = curret.by;
		int rx = curret.rx;
		int ry = curret.ry;

		if (map[ry][rx] == 'O' && map[by][bx] != 'O') {
			cnt = curret.count;
			break;
		}


		for (int i = 0; i < 4; i++) {
			int nbx = bx;
			int nby = by;
			int nrx = rx;
			int nry = ry;
			while (1) {
				if (map[nby][nbx] != '#' && map[nby][nbx] != 'O') {
					nbx += xdir[i];
					nby += ydir[i];
				}
				else {
					if (map[nby][nbx] == '#') {
						nbx -= xdir[i];
						nby -= ydir[i];
					}
					break;
				}
			}

			while (1) {
				if (map[nry][nrx] != '#' && map[nry][nrx] != 'O') {
					nrx += xdir[i];
					nry += ydir[i];
				}
				else {
					if (map[nry][nrx] == '#') {
						nrx -= xdir[i];
						nry -= ydir[i];
					}
					break;
				}
			}

			if (nbx == nrx && nby == nry) {
				if (map[nry][nrx] != 'O') {
					int r_dist = abs(nrx - rx) + abs(nry - ry);
					int b_dist = abs(nbx - bx) + abs(nby - by);
					if (r_dist > b_dist) {
						nrx -= xdir[i];
						nry -= ydir[i];
					}
					else {
						nbx -= xdir[i];
						nby -= ydir[i];
					}
				}
			}
			if (check[nry][nrx][nby][nbx] == false) {
				check[nry][nrx][nby][nbx] = true;
				INFO next;
				next.bx = nbx;
				next.by = nby;
				next.rx = nrx;
				next.ry= nry;
				next.count = curret.count + 1;
				q.push(next);
			}

		}
		

	}

}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >>map[i][j];
			if (map[i][j] == 'B') {
				start.by = i;
				start.bx = j;
			}
			else if (map[i][j] == 'R') {
				start.ry = i;
				start.rx = j;
			}
		}
	}
	start.count = 0;
	bfs();
	cout << cnt;
}
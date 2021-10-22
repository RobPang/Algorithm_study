// 마법사 상어와 파이어볼
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;

struct Fireball
{
	int m, d, s;
};

int dirx[8] = { 0,1,1,1,0,-1,-1,-1 };
int diry[8] = { -1,-1,0,1,1,1,0,-1 };

queue<Fireball> map[50][50];
queue<Fireball> temp[50][50];
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c , m , d, s;
		Fireball f;
		cin >> r >> c >> f.m >> f.s >> f.d;
		map[r - 1][c - 1].push(f);
	}
	for (int cnt = 0; cnt < k; cnt++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				while (!map[y][x].empty()) {
					Fireball f = map[y][x].front();
					map[y][x].pop();
					int nx = (x + dirx[f.d] * f.s) % n;
					int ny = (y + diry[f.d] * f.s) % n;
					if (nx < 0) nx += n;
					if (ny < 0) ny += n;
					temp[ny][nx].push(f);
				}
			}
		}

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				int mass = 0;
				int speed = 0;
				int dir = 0;
				int cnt = 0;
				int flag = 0;
				int nd;
				while (!temp[y][x].empty()) {
					Fireball f = temp[y][x].front();
					temp[y][x].pop();
					mass += f.m;
					speed += f.s;
					nd =  f.d;;
					if (cnt == 0) dir = (f.d % 2);
					else {
						if (dir != (f.d %2)) flag = 1;
					}
					cnt++;
				}
				
				if (cnt != 0) {
					speed = speed / cnt;
					if (cnt > 1) { 
						mass = mass / 5; 
						if (mass != 0) {
							if (flag == 1) {
								Fireball f;
								f.m = mass;
								f.s = speed;
								f.d = 1;
								map[y][x].push(f);
								f.d = 3;
								map[y][x].push(f);
								f.d = 5;
								map[y][x].push(f);
								f.d = 7;
								map[y][x].push(f);
							}
							else {
								Fireball f;
								f.m = mass;
								f.s = speed;
								f.d = 0;
								map[y][x].push(f);
								f.d = 2;
								map[y][x].push(f);
								f.d = 4;
								map[y][x].push(f);
								f.d = 6;
								map[y][x].push(f);
							}
						}
						
					}	
					else {
						Fireball f;
						f.m = mass;
						f.s = speed;
						f.d = nd;
						map[y][x].push(f);
					}
				}
				
			}
		}
	}

	int res = 0;
	
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			while (!map[y][x].empty()) {
				Fireball f = map[y][x].front();
				map[y][x].pop();
				res += f.m;
			}
		}
	}
	cout << res;
}
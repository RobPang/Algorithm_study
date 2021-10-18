// 먹이의 위치와 time을 저장했다가 비교하는 식으로
#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int map[20][20];
int n;
int dirx[4] = { 0, -1, 1, 0 };
int diry[4] = { -1, 0, 0, 1 };

struct Shark {
	int y; int x;
	int size; int cnt;
	int time;
};

Shark shark;


void bfs() {
	queue<Shark> q;
	q.push(shark);
	bool check[20][20] = { false };
	check[shark.y][shark.x] = true;
	while (!q.empty()) {
		Shark csh = q.front();
		int y = csh.y;
		int x = csh.x;
		q.pop();
		if (map[y][x] < csh.size && map[y][x] != 0) {	//예전 위치 저장
			map[y][x] = 0;
			csh.cnt++;
			if (csh.cnt == csh.size) {
				csh.size++;
				csh.cnt = 0;
			}
			shark = csh;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = csh.y + diry[i];
			int nx = csh.x + dirx[i];

			if (!(ny >= 0 && nx >= 0 && nx < n && ny < n)) continue;
			if (check[ny][nx]) continue;
			if (map[ny][nx] > csh.size) continue;
			check[ny][nx] = true;
			
			Shark nsh = csh;
			nsh.y = ny; nsh.x = nx; nsh.time++;
			q.push(nsh);

		}
	}

}


int main() {
	cin >> n;
	//Shark shark;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.x = j;
				shark.y = i;
				shark.cnt = 0;
				shark.size = 2;
				shark.time = 0;
				map[i][j] = 0;
			}
		}
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] < shark.size && map[i][j] != 0) {
					flag = true;
				}
			}
		}
		if(flag) bfs();
		
	}
	cout << shark.time;

}
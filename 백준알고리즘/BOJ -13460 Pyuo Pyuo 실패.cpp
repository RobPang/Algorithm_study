// 구현 실패 pyuo puyo 구현 버리자#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

char field[13][6];
char field_dot[13][6];
char prefield[13][6];
bool check[13][6];

int xdir[4] = { 0,1,0,-1 };
int ydir[4] = { -1,0,1,0 };

void bfs(int row, int col) {
	queue<pair<int,int> > q;
	int cnt = 0;
	q.push({ col,row});
	char puyo = field_dot[row][col];
	check[row][col] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
	//	field_dot[x][y] = ' ';
		
		for (int i = 0; i < 4; i++) {
			int dx, dy;
			dx = x + xdir[i];
			dy = y + ydir[i];
			if (!(dx >= 0 && dy >= 1 && dx <= 5 && dy <= 12)) continue;
			if (field_dot[dy][dx] == puyo && !(check[dy][dx])) {
				check[dy][dx] = true;
				q.push({dx,dy});
			}
		}
	}
	if (cnt >= 4) {
		for (int i = 1; i <= 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (check[i][j] && field_dot[i][j] == puyo) {
					field_dot[i][j] = ' ';
				}
				
			}
		}
	}

}


int main() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> field[i][j];
		}
	}
	for (int i = 0; i < 6; i++) {
		field_dot[0][i] = '.';
	}
	int flag = 1;
	int pop = 0;
	for (int i = 1; i <= 12; i++) {
		for (int j = 0; j < 6; j++) {
			field_dot[i][j] = field[i][j];
			prefield[i][j] = field_dot[i][j];
		}
	}
	while (flag) {
		

		for (int i = 1; i <= 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!check[i][j] && field_dot[i][j] != '.') {
					bfs(i, j);
				}
			}
		}
		
		for (int i = 1; i <= 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (field_dot[i][j] == ' ') {
					for (int k = i; k >= 1; --k) {
						field_dot[k][j] = field_dot[k-1][j];
						field_dot[k - 1][j] = '.';
					}
				}
			}
		}
		flag = 0;
		for (int i = 1; i <= 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (prefield[i][j] != field_dot[i][j]) {
					prefield[i][j] = field_dot[i][j];
					flag = 1;
					
				}
				check[i][j] = false;
			}
		}
		if (flag == 1) pop++;
		
	}

	cout << pop;

	
}
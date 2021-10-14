// 삼성기출 주사위 굴리기 - 다시 풀 필요있음
#include <iostream>

using namespace std;

int map[21][21];
int n, m, k;
int order[1001];
int x, y;
int dice[6];
int diry[4] = {1, -1 , 0,  0};
int dirx[4] = { 0, 0 , -1 , 1 };

void rotate(int dir) {
	int temp[6];
	switch (dir)
	{
	case 0:
		temp[0] = dice[0];
		temp[1] = dice[4];
		temp[2] = dice[2];
		temp[3] = dice[5];
		temp[4] = dice[3];
		temp[5] = dice[1];
		break;
	case 1:
		temp[0] = dice[0];
		temp[1] = dice[5];
		temp[2] = dice[2];
		temp[3] = dice[4];
		temp[4] = dice[1];
		temp[5] = dice[3];
		break;
	case 2:
		temp[0] = dice[1];
		temp[1] = dice[2];
		temp[2] = dice[3];
		temp[3] = dice[0];
		temp[4] = dice[4];
		temp[5] = dice[5];
		break;
	case 3:
		temp[0] = dice[3];
		temp[1] = dice[0];
		temp[2] = dice[1];
		temp[3] = dice[2];
		temp[4] = dice[4];
		temp[5] = dice[5];
		break;

	}
	for (int i = 0; i < 6; i++) {
		dice[i] = temp[i];
	}
}

int main() {
	cin >> n >> m;
	cin >> x >> y;
	cin >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
			order[i] = a-1;
	}
	for (int i = 0; i < 6; i++) {
		dice[i] = 0;
	}
	int nx = x;
	int ny = y;
	for (int i = 0; i < k; i++) {
		nx += dirx[order[i]];
		ny += diry[order[i]];
		if (!(nx >= 0 && ny >= 0 && nx < n && ny < m)) {
			nx -= dirx[order[i]];
			ny -= diry[order[i]];
			continue;
		}
		rotate(order[i]);
		if (map[nx][ny] == 0) {
			map[nx][ny] = dice[3];
		}
		else {
			dice[3] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[1] << '\n';
	}
}
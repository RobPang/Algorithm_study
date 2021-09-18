#include <iostream>

using namespace std;

int n;

int map[17][17];

//0 : 가로, 1 : 세로, 2 : 대각선
int dxdir[3] = { 1,0,1 };
int dydir[3] = { 0,1,1 };
long long cnt;

bool Check(int x, int y, int dir) {
	int _x, _y;
	_x = x + dxdir[dir];
	_y = y + dydir[dir];
	if (_x > n - 1 | _y > n - 1) {
		return false;
	}
	else if (map[_x][_y] == 1) return false;
	if (dir == 2) {
		if (map[_x][y] + map[x][_y] > 0) return false;
	}
	return true;
}

void DFS(int x, int y, int dir) {
	if ((x == y)&(y == (n - 1))) {
		cnt++;
		return;
	}
	switch (dir)
	{
	case 0:
		if (Check(x, y, 0)) DFS(x + 1, y, 0);
		if (Check(x, y, 2)) DFS(x + 1, y + 1, 2);
		break;
	case 1:
		if (Check(x, y, 1)) DFS(x, y + 1, 1);
		if (Check(x, y, 2)) DFS(x + 1, y + 1, 2);
		break;
	case 2:
		if (Check(x, y, 0)) DFS(x + 1, y, 0);
		if (Check(x, y, 1)) DFS(x, y + 1, 1);
		if (Check(x, y, 2)) DFS(x + 1, y + 1, 2);
		break;
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	cnt = 0;
	DFS(1, 0, 0);

	cout << cnt << '\n';

}
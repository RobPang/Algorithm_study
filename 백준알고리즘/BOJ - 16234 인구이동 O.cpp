//인구 이동 - 배열크기 잘정하기

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, l, r;
int map[51][51];
int check[51][51];
int label;
int value[2501];

int dirx[4] = {1,0,-1,0};
int diry[4] = {0,1,0,-1};

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push({ y,x });
	check[y][x] = label;
	int sum = 0;
	int cnt = 0;
	while (!q.empty())	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		sum += map[cy][cx];
		cnt++;
		for (int i = 0; i < 4; i++) {
			int ny = cy + diry[i];
			int nx = cx + dirx[i];

			if (!(nx >= 0 && ny >= 0 && ny < n && nx < n)) continue;
			if (check[ny][nx] != 0) continue;
			if (abs(map[ny][nx] - map[cy][cx]) >=l && abs(map[ny][nx] - map[cy][cx]) <= r) {
				check[ny][nx] = label;
				q.push({ ny, nx });

			}
		}
	}
	value[label] = sum / cnt;

}

void copy(int temp[51][51], int insert[51][51]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = insert[i][j];
		}
	}
}

bool compare(int temp[51][51], int insert[51][51]) {
	bool result = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] != insert[i][j]) {
				result = false;
			}
		}
	}
	return result;
}


int main() {
	cin >> n >> l >> r;
	memset(map, 0, sizeof(map));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	label = 0;
	int cnt = 0;
	bool flag = false;
	while (1) {
		if (cnt >= 2000) break;
		flag = false;
		int temp[51][51];
		copy(temp, map);
		label = 0;
		memset(value, 0, sizeof(value));
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0) {
					label++;
					bfs(i, j);
				}	
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int avg = value[check[i][j]];
				if (map[i][j] != avg) {
					map[i][j] = avg;
					flag = true;
				}
			}
		}

		if (compare(temp, map)) break;
		cnt++;
	}
	cout << cnt;
}

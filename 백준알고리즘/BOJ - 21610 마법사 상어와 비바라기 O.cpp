// 품
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct CLOUD
{
	int y, x;
};

int map[50][50];
int n, m;
int d[100];
int s[100];
bool check_rain[50][50];

int dirx[8] = { -1, -1, 0, 1, 1,1,0,-1 };
int diry[8] = { 0, -1, -1, -1,0,1,1, 1 };

void make_cloud() {

}
queue<pair <int, int > > cloud;
queue<pair<int, int > > copy_pos;


void copy() {
	bool check[50][50] = { false, };
	while (!copy_pos.empty()) {
		int y = copy_pos.front().first;
		int x = copy_pos.front().second;
		check[y][x] = true;
		copy_pos.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + diry[2 * i + 1];
			int nx = x + dirx[2 * i + 1];
			if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
			if (map[ny][nx] != 0) {
				map[y][x]++;
			}	
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] >= 2 && (check[y][x] == false)) {
				cloud.push({ y,x });
				map[y][x] -= 2;
			}
		}
	}

}
void move(int d, int s) {
	
	while (!cloud.empty()) {
		int y = cloud.front().first;
		int x = cloud.front().second;
		cloud.pop();
		int ny = (y + s * diry[d]) % n;
		if (ny < 0) ny += n;
		else if (ny >= n) ny -= n;
	
		int nx = (x + s * dirx[d]) % n;
		if (nx < 0) nx += n;
		else if (nx >= n) nx -= n;

		map[ny][nx] += 1;
		copy_pos.push({ ny,nx });
		
	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int dir, si;
		cin >> dir >> si;
		d[i] = dir - 1;
		s[i] = si;
	}
	cloud.push({n-1,0});
	cloud.push({ n - 1,1 });
	cloud.push({ n - 2,0 });
	cloud.push({ n - 2,1 });

	for (int i = 0; i < m; i++) {
		move(d[i], s[i]);
		//queue pop()
		copy(); // 물복사버그 와 구름 생성

	}
	int res = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			res += map[y][x];
		}
	}
	cout << res;
}
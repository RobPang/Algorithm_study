#include <iostream>
#include <queue>

using namespace std;

int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0, 1, 0,-1 };

int n;
int map[500][500];
int res;
void spred(int y, int x, int dir) {
	int cur_sand = map[y][x];
	int remain_sand = cur_sand;
	int nx = x + dirx[(dir+2)%4] + dirx[(dir + 3) % 4];
	int ny = y + diry[(dir + 2) % 4] + diry[(dir + 3) % 4];
	int discount1 = cur_sand / 100;
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount1;
		remain_sand -= discount1;
	}
	else {
		map[ny][nx] += discount1;
		remain_sand -= discount1;
	}
	nx = x + dirx[(dir + 2) % 4] + dirx[(dir + 1) % 4];
	ny = y + diry[(dir + 2) % 4] + diry[(dir + 1) % 4];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount1;
		remain_sand -= discount1;

	}
	else {
		map[ny][nx] += discount1;
		remain_sand -= discount1;
	}
	int discount7 = cur_sand * 0.07;
	nx = x + dirx[(dir + 3) % 4];
	ny = y + diry[(dir + 3) % 4];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount7;
		remain_sand -= discount7;

	}
	else {
		map[ny][nx] += discount7;

		remain_sand -= discount7;
	}
	nx = x + dirx[(dir + 1) % 4];
	ny = y + diry[(dir + 1) % 4];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount7;
		remain_sand -= discount7;

	}
	else {
		map[ny][nx] += discount7;

		remain_sand -= discount7;
	}
	int discount2 = cur_sand * 0.02;
	nx = x + 2*dirx[(dir + 3) % 4];
	ny = y + 2 * diry[(dir + 3) % 4];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount2;
		remain_sand -= discount2;

	}
	else {
		map[ny][nx] += discount2;

		remain_sand -= discount2;
	}
	nx = x + 2 * dirx[(dir + 1) % 4];
	ny = y + 2 * diry[(dir + 1) % 4];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount2;
		remain_sand -= discount2;

	}
	else {
		map[ny][nx] += discount2;

		remain_sand -= discount2;
	}
	int discount10 = cur_sand / 10;
	nx = x + dirx[dir] + dirx[(dir + 3) % 4];
	ny = y + diry[dir] + diry[(dir + 3) % 4];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount10;
		remain_sand -= discount10;

	}
	else {
		map[ny][nx] += discount10;

		remain_sand -= discount10;
	}
	nx = x + dirx[(dir) % 4] + dirx[(dir + 1) % 4];
	ny = y + diry[(dir) % 4] + diry[(dir + 1) % 4];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount10;
		remain_sand -= discount10;

	}
	else {
		map[ny][nx] += discount10;

		remain_sand -= discount10;
	}
	int discount5 = cur_sand * 0.05;
	nx = x + 2 *dirx[dir];
	ny = y +2* diry[dir];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += discount5;
		remain_sand -= discount5;

	}
	else {
		map[ny][nx] += discount5;
		remain_sand -= discount5;
	}

	nx = x + dirx[dir];
	ny = y + diry[dir];
	if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) {
		res += remain_sand;
	}
	else {
		map[ny][nx] += remain_sand;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int dir_cnt = 0;
	int dir = 0;
	int speed = 1;
	int mid = n / 2;
	int tx = mid;
	int ty = mid;
	res = 0;
	while (!(tx == 0 && ty == 0)) {
		for (int i = 0; i < speed; i++) {
			tx += dirx[dir];
			ty += diry[dir];
			spred(ty, tx, dir);
			if (tx == 0 && ty == 0) break;
		}
		dir = (dir + 1) % 4;
		dir_cnt++;
		if (dir_cnt == 2) {
			dir_cnt = 0;
			speed++;
		}
	}
	cout << res;
}
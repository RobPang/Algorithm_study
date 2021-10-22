//상어 초등학교 - 빈공간 탐색 X, MAX값 선언시 초기화 주의
#include <iostream>
#include <vector>
#include <queue>

struct STUD {
	int s[4];
	bool sit;
	int y, x;
};

using namespace std;
int n;
//int student[401][4];
STUD student[401];
int seq[401];
int map[20][20];
int dirx[4] = { 0,-1,0,1 };
int diry[4] = { -1,0,1,0 };


void in_map(int idx) {
	int bf[20][20] = { 0, };
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		int bf_num = student[idx].s[i];
		if (student[bf_num].sit == true) {
			for (int dir = 0; dir < 4; dir++) {
				int ny = student[bf_num].y + diry[dir];
				int nx = student[bf_num].x + dirx[dir];
				if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
				if (map[ny][nx] != 0) continue;
				flag = 1;
				bf[ny][nx] += 10;
			}
		}
	}
	int res_y = 0, res_x = 0;

	if (flag == 1) {
		int max = 5; int cnt_max = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (max < bf[y][x]) {
					int cnt = 0;
					for (int dir = 0; dir < 4; dir++) {
						int ny = y + diry[dir];
						int nx = x + dirx[dir];
						if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
						if (map[ny][nx] != 0) continue;
						cnt++;
					}
					cnt_max = cnt;
					max = bf[y][x];
					res_y = y;
					res_x = x;
				}
				else if (max == bf[y][x]) {
					int cnt = 0;
					for (int dir = 0; dir < 4; dir++) {
						int ny = y + diry[dir];
						int nx = x + dirx[dir];
						if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
						if (map[ny][nx] != 0) continue;
						cnt++;
					}
					if (cnt_max < cnt) {
						cnt_max = cnt;
						res_y = y;
						res_x = x;
					}
				}
			}
		}
		student[idx].sit = true;
		student[idx].y = res_y;
		student[idx].x = res_x;
		map[res_y][res_x] = idx;
		return;
	}
	int max = -1;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] != 0) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + diry[dir];
				int nx = x + dirx[dir];
				if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
				if (map[ny][nx] != 0) continue;
				cnt++;
			}
			if (max < cnt) {
				max = cnt;
				res_y = y;
				res_x = x;
			}
				
		}
	}
	student[idx].sit = true;
	student[idx].y = res_y;
	student[idx].x = res_x;
	map[res_y][res_x] = idx;
	return;

}

int main() {
	cin >> n;
	for (int i = 1; i <= n*n; i++) {
		int idx, s1, s2, s3, s4;
		cin >> idx >> s1 >> s2 >> s3 >> s4;
		seq[i] = idx;
		student[idx].s[0] = s1;
		student[idx].s[1] = s2;
		student[idx].s[2] = s3;
		student[idx].s[3]= s4;
		student[idx].sit = false;
	}

	for (int i = 1; i <= n*n; i++) {
		in_map(seq[i]);
	}
	int res = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + diry[dir];
				int nx = x + dirx[dir];
				if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
				for (int i = 0; i < 4; i++) {
					if(map[ny][nx] == student[map[y][x]].s[i]) cnt++;
				}
				
			}
			if (cnt == 1) {
				res += 1;
			}
			else if (cnt == 2) {
				res += 10;
			}
			else if (cnt == 3) {
				res += 100;
			}
			else if (cnt == 4) {
				res += 1000;
			}

		}
	}
	cout << res;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct horse {
	int x, y, d;
};
horse h[10];
int n, k, flag;
int  map[12][12];
vector<int> pos[12][12];

int dirx[4] = { 1,-1,0,0 };
int diry[4] = { 0,0,-1,1 };

void move(int idx) {
	//0 흰색 , 1 빨간색, 2 파란색
	int cy = h[idx].y;
	int cx = h[idx].x;
	int cd = h[idx].d; int nd = 0;
	int ny = cy + diry[h[idx].d];
	int nx = h[idx].x + dirx[h[idx].d];
	if (!(ny >= 0 && nx >= 0 && ny < n && nx < n) || map[ny][nx] == 2) {
		ny = h[idx].y - diry[h[idx].d];
		nx = h[idx].x - dirx[h[idx].d];
		if (cd == 0) {
			nd = 1;
		}
		else if (cd == 1) {
			nd = 0;
		}
		else if (cd == 2) {
			nd = 3;
		}
		else {
			nd = 2;
		}
		h[idx].d = nd;
		if (!(ny >= 0 && nx >= 0 && ny < n && nx < n) || map[ny][nx] == 2) {
			ny = h[idx].y;
			nx = h[idx].x;
			return;
		}
	}
	if (map[ny][nx] == 1) {
		int s_idx = 0;
		for (int i = 0; i < pos[cy][cx].size(); i++) {
			int temp = pos[cy][cx][i];
			if (temp == idx) {
				s_idx = i;
				break;
			}
		}
		for (int i = pos[cy][cx].size() - 1; i >= s_idx; --i) {
			int temp = pos[cy][cx][i];
			h[temp].y = ny; h[temp].x = nx;
			pos[ny][nx].push_back(temp);
			pos[cy][cx].pop_back();
		}
	
	}
	else {
		int s_idx = 0;
		for (int i = 0; i < pos[cy][cx].size(); i++) {
			int temp = pos[cy][cx][i];
			if (temp == idx) {
				s_idx = i;
				break;
			}
		}
		for (int i = s_idx; i < pos[cy][cx].size(); i++) {
			int temp = pos[cy][cx][i];
			h[temp].y = ny; h[temp].x = nx;
			pos[ny][nx].push_back(temp);
		}

		for (int i = pos[cy][cx].size() -1; i >=s_idx; --i) {
			pos[cy][cx].pop_back();
		}
		
	}
	if (pos[ny][nx].size() >= 4) flag = 1;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			pos[i][j].clear();
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y, d;
		cin >> y >> x >> d;
		h[i].x = x - 1;
		h[i].y = y - 1;
		h[i].d = d - 1;
		pos[y - 1][x - 1].push_back(i);
	}
	int res = -1;
	int cnt = 0;
	flag = 0;
	while (flag == 0) {
		if (cnt > 1000) break;
		cnt++;
		for (int i = 0; i < k; i++) {
			move(i);
			if (flag == 1) {
				res = cnt;
				break;
			}
		}
	}
	cout << res;

}
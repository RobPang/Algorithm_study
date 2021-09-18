//전쟁 - 전투 BFSorDFS 문제 조건을 잘 파악하자 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;




int xdir[4] = { 0, 1, 0 , -1 };
int ydir[4] = { 1, 0, -1, 0 };
int n, k;
int wcnt;
int bcnt;

int map[101][101];
bool ch[101][101];

void wDFS(int x, int y) {
	
	if (!(x >= 0 && y >= 0 && x < k && y < n && map[x][y] == 'W')) return;
	ch[x][y] = true;
	wcnt++;

	for (int i = 0; i < 4; i++) {
		if (!ch[x + xdir[i]][y + ydir[i]]) {
			wDFS(x + xdir[i], y + ydir[i]);
		}
	}
}

void bDFS(int x, int y) {
	if (!(x >= 0 && y >= 0 && x < k && y < n && map[x][y] == 'B')) return;
	ch[x][y] = true;
	bcnt++;

	for (int i = 0; i < 4; i++) {
		if (!ch[x + xdir[i]][y + ydir[i]]) {
			bDFS(x + xdir[i], y + ydir[i]);
		}
	}
}

int pow(int a) {
	return a * a;
}

int main() {
	string str;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j];
		}
	}
	int wsum = 0;
	int bsum = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (!(ch[i][j])) {
				if (map[i][j] == 'B') {
					bDFS(i, j);
					bsum += pow(bcnt);
					bcnt = 0;
				}
				else if (map[i][j] == 'W') {
					wDFS(i, j);
					wsum += pow(wcnt);
					wcnt = 0;
				}
			}

		}
	}

	cout << wsum << ' ' << bsum;

}
// 톱니바퀴
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int k;
int	cir[4][8];
int dir[100];
int cn[100];

bool check[4];

void rotate(int num, int dir) {
	if (num > 3) return;
	if (num < 0) return;
	int temp[4][8];
	check[num] = true;
	if ((num -1>=0 ) && cir[num][6] != cir[num-1][2]) {
		if (!check[num - 1]) {
			rotate(num - 1, -dir);
		}
	}
	if ((num + 1 <4 ) && cir[num][2] != cir[num + 1][6]) {
		if (!check[num + 1]) {
			rotate(num + 1, -dir);
		}
	}
	if (dir == 1) {
		temp[num][0] = cir[num][7];
		temp[num][1] = cir[num][0];
		temp[num][2] = cir[num][1];
		temp[num][3] = cir[num][2];
		temp[num][4] = cir[num][3];
		temp[num][5] = cir[num][4];
		temp[num][6] = cir[num][5];
		temp[num][7] = cir[num][6];
	}
	else if (dir == -1) {
		temp[num][0] = cir[num][1];
		temp[num][1] = cir[num][2];
		temp[num][2] = cir[num][3];
		temp[num][3] = cir[num][4];
		temp[num][4] = cir[num][5];
		temp[num][5] = cir[num][6];
		temp[num][6] = cir[num][7];
		temp[num][7] = cir[num][0];
	}
	for (int i = 0; i < 8; i++) {
		cir[num][i] = temp[num][i];
	}

}

int main() {
	for (int i = 0; i < 4; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < 8; j ++ ) {
			cir[i][j] = input[j] -'0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> cn[i];
		cin >> dir[i];
	}
	for (int i = 0; i < k; i++) {
		rotate(cn[i]-1, dir[i]);
		for (int j = 0; j < 4; j++) {
			check[j] = false;
		}
	}
	int cnt = 0;
	cnt = cir[0][0] + 2 * cir[1][0] + 4 * cir[2][0] + 8 * cir[3][0];
	cout << cnt << '\n';
}

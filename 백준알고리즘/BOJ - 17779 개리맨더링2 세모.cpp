#include <iostream>
#include <cmath>

using namespace std;

int map[21][21];
int n;

int solve(int x, int y, int d1, int d2) {
	int temp[21][21] = { 0, };
	temp[x][y] = 5;
	for (int i = 1; i <= d1; i++) {
		temp[x + i][y - i] = 5;
		temp[x + d2 + i][y + d2 - i] = 5;
	}

	for (int i = 1; i <= d2; i++) {
		temp[x + i][y + i] = 5;
		temp[x + d1 + i][y - d1 +i] = 5;
	}
	int aa = 0;
	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			if (temp[r][c] == 5) break;
			aa += map[r][c];
		}
	}
	int bb = 0;
	for (int r = 1; r <= x + d2; r++) {
		for (int c = n; c > y; --c) {
			if (temp[r][c] == 5) break;
			bb += map[r][c];
		}
	}

	int cc = 0;
	for (int r = x+d1; r <= n; r++) {
		for (int c = 1; c < y-d1+d2; c++) {
			if (temp[r][c] == 5) break;
			cc += map[r][c];
		}
	}

	int dd = 0;
	for (int r = x + d2 +1; r <= n; r++) {
		for (int c = n; c >= y - d1 + d2; --c) {
			if (temp[r][c] == 5) break;
			dd += map[r][c];
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += map[i][j];
		}
	}
	int ee;
	ee = sum - aa - bb - cc - dd;

	int max_value = max(ee, max(dd, max(cc, max(bb, aa))));
	int min_value = min(ee, min(dd, min(cc, min(bb, aa))));

	return (max_value - min_value);
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int res = 0x7fffffff;
	for (int x = 1; x < n; x++) {
		for (int y = 1; y < n; y++) {
			for (int d1 = 1; d1 < n; d1++) {
				for (int d2 = 1; d2 < n; d2++) {
					if (x + d1 + d2 > n) continue;
					if (1 > y - d1)	continue;
					if (y + d2 > n)	continue;
					res = min(res,solve(x, y, d1, d2));
				}
			}
		}
	}
	cout << res;

}
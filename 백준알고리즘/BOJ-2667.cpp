//단지번호 붙히기 - BFS DFS 관련 문제
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstdio>

using namespace std;
int cnt;
int n;
int arr[25][25];
int dan[25][25];
int dir[2][4] = { {0,1,0,-1}, {1,0,-1,0} };

void bfs(int col, int row) {
	for (int i = 0; i < 4; i++) {
		int dx = col + dir[0][i];
		int dy = row + dir[1][i];
		if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
			if (arr[dx][dy] == 1 && dan[dx][dy] == 0) {
				dan[dx][dy] = 1;
				cnt++;
				bfs(dx, dy);
			}

		}

	}
	
}

int main() {
	//cin >> n;

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cin >> arr[i][j];
	//	}
	//}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]); // 정수 한개씩 입력받음
		}
	}
	vector<int> v;
	cnt = 0;
	int result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && dan[i][j] == 0) {
				dan[i][j] = 1;
				cnt++;
				bfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	cout << v.size()<<'\n';
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << '\n';
	}


}

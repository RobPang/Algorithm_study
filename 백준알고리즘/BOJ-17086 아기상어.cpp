//bfs 문제지만 bfs를 쓰지않아 버림,
// bfs로 작성시 빈칸에서 상어 위치 확인 x 
// 상어칸부터 빈칸들을 bfs, 상어칸 주변부터 거리 정보를 채워나가면 마지막으로 가장 먼칸에 가장만 거리가 입력됨
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int map[51][51];

int main() {
	int n, m;
	cin >> n >> m;
	int temp;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1) {
				v.push_back({ i,j });
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int min = 50;
			for (int k = 0; k < v.size(); k++) {
				int x = v.at(k).first;
				int y = v.at(k).second;
				int c;
				if (abs(i - x) > abs(j - y)) {
					c = abs(i - x);
				}
				else {
					c = abs(j - y);
				}
				min = (min > c) ? c : min;
			}
			max = (max > min) ? max : min;
		}
	}
	cout << max;

}
//제출에서 실패함 ㅠ

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

int map[50][50];
int sel[10];
vector<pair <pair < int, int> , int > >  birus;
queue<pair <pair < int, int>, int > >  tempbirus;


int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0, 1, 0, -1 };

int res;
void bfs() {
	int time = 0;
	int temp[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = map[i][j];
		}
	}
	

	queue<pair <pair < int, int>, int > >  nextbirus;
	for (int i = 0; i < 10; i++) {
		if (sel[i] == 1) {
			pair<pair<int, int>, int > temp = birus[i];
			nextbirus.push(temp);
		}
	}

	bool check[50][50] = { false };
	check[nextbirus.front().first.first][nextbirus.front().first.second] = true;
	temp[nextbirus.front().first.first][nextbirus.front().first.second] = -1;
	while (!nextbirus.empty()) {
		int y = nextbirus.front().first.first;
		int x = nextbirus.front().first.second;
		int ntime = nextbirus.front().second;
		
		if(time < ntime) time = ntime;
		for (int i = 0; i < 4; i++) {
			int ny = y + diry[i];
			int nx = x + dirx[i];
			
			if (!(nx >= 0 && ny >= 0 && nx < n && ny < n)) continue;
			if (check[ny][nx]) continue;
			check[ny][nx] = true;
			if (map[ny][nx] == 1) {
				temp[ny][nx] = -1;
				continue;
			}
			if (map[ny][nx] == 2) {
				nextbirus.push({{ ny,nx }, ntime});
				temp[ny][nx] = -1;
			}
			else {
				nextbirus.push({ { ny,nx }, ntime+1 });
				temp[ny][nx] = -1;
			}

		}

		nextbirus.pop();		
	}
	
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] != -1 && map[i][j] != 1) {
				ok = false;
			}
		}
	}
	if (ok) {
		if (res < 0) res = time;
		else if (res > time) res = time;
	}

}
int asdf;
void dfs(int n , int idx) {
	if (n == m) {
		asdf++;
		bfs();
		return;
	}
	for (int i = idx; i < birus.size(); i++) {
		//pair<pair<int, int> , int > temp = birus[i];
		sel[i] = 1;
		//birus.pop();
	//	tempbirus.push(temp);
		dfs(n + 1, i+1);
		sel[i] = 0;
	//	tempbirus.pop();
		//map[temp.first.first][temp.first.second] = 2;
		//birus.push(temp);
	}

}

int main() {
	cin >> n  >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				birus.push_back({{ i,j },0});
			}
		}
	}
	
	res = -1;
	dfs(0,0);
//	cout << asdf << 'k' << '\n';
	cout << res << '\n';


}

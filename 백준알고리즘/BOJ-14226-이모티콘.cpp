//이모티콘 - bfs, 조건에 따라 방문여부 체크배열의 크기가 달라질수 있어
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool check[2000][2000];
int cc;
int cnt;

void bfs(int n) {
	queue<pair<int,pair<int,int>>> q;
	q.push({ 1,{0,0} });
	check[1][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int count = q.front().second.first;
		int temp = q.front().second.second;
		q.pop();
		if (x == n) {
			cout << count;
			return;
		}

		
		int y = x - 1;
		if (y >= 2 && !check[y][temp]) {
			q.push({ y,{count + 1,temp} });
			check[y][temp] = true;
		}

		y = x + temp;
		if (temp > 0 && y <1001 && !check[y][temp]){
			check[y][temp] = true;
			q.push({ y,{count + 1,temp} });
		}

		if (!check[x][x]) {
			check[x][x] = true;
			q.push({ x,{count + 1,x} });
		}
		

	}

}

int main() {
	int n; cin >> n;
	
	bfs(n);

}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[1001];
bool dch[1001];
bool bch[1001];

void DFS(int point) {
	if (dch[point]) return;
	dch[point] = true;
	cout << point << ' ';

	for (int i = 0; i < v[point].size(); i++) {
		DFS(v[point].at(i));
	}

}

void BFS(int point) {
	queue<int> q;
	q.push(point);
	bch[point] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!bch[y]) {
				q.push(y);
				bch[y] = true;
			}
		}
	}

}


int main() {
	int n, k, c;
	cin >> n >> k >> c;

	for (int i = 0; i < k; i++) {
		int a;
		int b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	DFS(c);
	cout << '\n';
	BFS(c);

}
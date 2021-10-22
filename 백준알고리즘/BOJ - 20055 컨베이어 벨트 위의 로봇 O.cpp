//컨테이너 벨트위의 로봇 - 무지성 for문

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, k;
int a[200];
int robot[100];

struct ROBOT {
	int pos;
};

int main() {
	
	cin >> n >> k;
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i]; 
	}
	
	int cnt = 0;
	int robot_cnt = 0;
	while (1) {
		cnt++;
		int temp = a[2*n-1];
		for (int i = 2*n-1; i > 0; --i) {
			a[i] = a[i - 1];
		}
		a[0] = temp;
		int imijkdfn = a[1];
		for (int i = n - 1; i > 0; --i) {
			robot[i] = robot[i - 1];
		}
		robot[0] = 0;
		if (robot[n-1] == 1) {
			robot[n-1] = 0;
		}
		for (int i = n - 1; i > 0; --i) {
			if (a[i] >= 1 && robot[i] != 1 && robot[i-1] != 0) {
				robot[i] = robot[i - 1];
				robot[i - 1] = 0;
				a[i]--;
			}
		}
		if (a[0] != 0) {
			a[0]--;
			robot_cnt++;
			robot[0] = 1;
		}
		robot[0];
		int k_cnt = 0;
		for(int i = 0; i < 2*n ; i++) {
			if (a[i] == 0) k_cnt++;
		}
		if (k_cnt >= k) {
			break;
		}
	}
	cout << cnt;
}
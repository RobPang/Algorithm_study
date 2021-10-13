//거북이 - 맨날 하던거 같은 느낌 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
char oper[501];

int main() {
	int n; cin >> n;
	string input;

	int dir = 0;
	int x, y;
	int x_min, x_max;
	int y_min, y_max;

	while (n--) {
		input.clear();
		cin >> input;
		dir = 0;
		x = 0; y = 0;
		x_min = 0; x_max = 0;
		y_min = 0; y_max = 0;
		for (int i = 0; i < input.size(); i++) {
			char op = input[i];
			if (op == 'F') {
				x += xdir[dir];
				y += ydir[dir];
				
				x_min = min(x, x_min);
				x_max = max(x, x_max);
				y_min = min(y, y_min);
				y_max = max(y, y_max);

			}
			else if (op == 'B') {
				x -= xdir[dir];
				y -= ydir[dir];

				x_min = min(x, x_min);
				x_max = max(x, x_max);
				y_min = min(y, y_min);
				y_max = max(y, y_max);
			}
			else if (op == 'L') {
				dir--;
				if (dir < 0) {
					dir = 3;
				}
			}
			else if (op == 'R') {
				dir++;
				if (dir > 3) {
					dir = 0;
				}
			}
		}
		cout << (x_max - x_min)* (y_max - y_min)<<'\n';

	}

}
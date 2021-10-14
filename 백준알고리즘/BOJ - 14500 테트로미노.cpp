// //잘못된 풀이
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <cstring>

// using namespace std;

// int n, m;
// int map[503][503];
// bool check[503][503];

// int dirx[4] = { 1,0,-1,0 };
// int diry[4] = { 0, 1, 0, -1 };
// int Max;

// int ex1[2][3] = { {1,1,1},{0,1,0} };
// int ex2[2][3] = { {0,1,0},{1,1,1} };
// int ex3[3][2] = { {0,1},{1,1},{0,1} };
// int ex4[3][2] = { {1,0},{1,1},{1,0 } };

// void dfs(int x, int y, int cnt, int sum) {
// 	check[x][y]= true;
// 	sum += map[x][y];
// 	if (cnt == 4) {
// 		if (Max < sum) Max = sum;
// 		return;
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		int nx = x + dirx[i];
// 		int ny = y + diry[i];
// 		if (!(nx >= 0 && ny >= 0 && nx < n && nx < m)) continue;
// 		if (check[nx][ny]) continue;
// 		check[nx][ny] = true;
// 		dfs(nx, ny, cnt + 1, sum);
// 		check[nx][ny] = false;
// 	}
// 	return;
// }


// int main() {
// 	cin >> n >> m;
// 	memset(map,0,sizeof(map));
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			cin >> map[i][j];
// 		}
// 	}
// 	int result = 0;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			dfs(i,j,1,0);

// 			int temp = 0;
// 			for (int x = 0; x < 2; x++) {
// 				for (int y = 0; y < 3; y++) {
// 					temp += ex1[x][y] * map[i+x][j+y];
// 				}
// 			}
// 			if (temp > Max) Max = temp;

// 			temp = 0;
// 			for (int x = 0; x < 2; x++) {
// 				for (int y = 0; y < 3; y++) {
// 					temp += ex2[x][ y] * map[i + x][j + y];
// 				}
// 			}
// 			if (temp > Max) Max = temp;

// 			temp = 0;
// 			for (int x = 0; x < 3; x++) {
// 				for (int y = 0; y < 2; y++) {
// 					temp += ex3[x][y] * map[i + x][j + y];
// 				}
// 			}
// 			if (temp > Max) Max = temp;

// 			temp = 0;
// 			for (int x = 0; x < 3; x++) {
// 				for (int y = 0; y < 2; y++) {
// 					temp += ex4[x][y] * map[i + x][j + y];
// 				}
// 			}
// 			if (temp > Max) Max = temp;

// 			if (result < Max) {
// 				result = Max;
// 			}
// 		}
// 	}

// 	cout << result;

// }

#include <stdio.h>
 
int n, m;
int map[503][503];
 
const char block[19][4][5] = {
    {
        "1111",
        "0000",
        "0000",
        "0000",
    },
    {
        "1000",
        "1000",
        "1000",
        "1000",
    },
    {
        "1100",
        "1100",
        "0000",
        "0000",
    },
    {
        "1000",
        "1000",
        "1100",
        "0000",
    },
    {
        "1110",
        "1000",
        "0000",
        "0000",
    },
    {
        "1100",
        "0100",
        "0100",
        "0000",
    },
    {
        "0010",
        "1110",
        "0000",
        "0000",
    },
    {
        "0100",
        "0100",
        "1100",
        "0000",
    },
    {
        "1000",
        "1110",
        "0000",
        "0000",
    },
    {
        "1100",
        "1000",
        "1000",
        "0000",
    },
    {
        "1110",
        "0010",
        "0000",
        "0000",
    },
    {
        "1000",
        "1100",
        "0100",
        "0000",
    },
    {
        "0110",
        "1100",
        "0000",
        "0000",
    },
    {
        "0100",
        "1100",
        "1000",
        "0000",
    },
    {
        "1100",
        "0110",
        "0000",
        "0000",
    },
    {
        "1110",
        "0100",
        "0000",
        "0000",
    },
    {
        "0100",
        "1100",
        "0100",
        "0000",
    },
    {
        "0100",
        "1110",
        "0000",
        "0000",
    },
    {
        "1000",
        "1100",
        "1000",
        "0000",
    }
};
 
int get_count(int sy, int sx, int k) {
    int ret = 0;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            ret += (block[k][y][x] - '0') * map[sy + y][sx + x];
        }
    }
    return ret;
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            scanf("%d", &map[y][x]);
        }
    }
 
    for (int y = n; y < n + 3; ++y) {
        for (int x = 0; x < m + 3; ++x) {
            map[y][x] = -100000;
        }
    }
 
    for (int y = 0; y < n + 3; ++y) {
        for (int x = m; x < m + 3; ++x) {
            map[y][x] = -100000;
        }
    }
 
    int ret = 0;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            for (int k = 0; k < 19; ++k) {
                int candi = get_count(y, x, k);
                if (ret < candi) {
                    ret = candi;
                }
            }
        }
    }
    printf("%d\n", ret);
 
    return 0;
}

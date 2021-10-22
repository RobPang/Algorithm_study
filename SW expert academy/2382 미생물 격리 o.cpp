/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
struct BIRUS {
	int num, dir;
	int max;
	void init() {
		this->num = 0;
		this->dir = 0;
		this->max = 0;
	}
};

BIRUS map[100][100];
BIRUS temp[100][100];

int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		cin >> n >> m >> k;
		
		for (int i = 0; i < k; i++) {
			int y, x, n, d;
			cin >> y >> x >> n >> d;
			map[y][x].num = n;
			if (d == 1) {
				map[y][x].dir = 3;

			}
			else if (d == 2) {
				map[y][x].dir = 1;

			}
			else if (d == 3) {
				map[y][x].dir = 0;

			}
			else if (d == 4) {
				map[y][x].dir = 2;

			}
		}
	
		for (int i = 0; i < m; i++) {
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (map[y][x].num == 0) continue;
					int num = map[y][x].num;
					int dir = map[y][x].dir;
					int ny = y + diry[dir];
					int nx = x + dirx[dir];
					if (nx == 0 || ny == 0 || nx == n - 1 || ny == n - 1) {
						num = num / 2;
						dir = (dir + 2) %4;
					}
					if (temp[ny][nx].max < num) {
						temp[ny][nx].max = num;
						temp[ny][nx].dir = dir;
					}
					temp[ny][nx].num += num;

					map[y][x].init();
				}
			}
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					if (temp[y][x].num == 0) continue;
					map[y][x].num = temp[y][x].num;
					map[y][x].dir = temp[y][x].dir;
					temp[y][x].init();
				}
			}
		}
		int cnt = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (map[y][x].num == 0) continue;
				cnt += map[y][x].num;
				map[y][x].init();
			}
		}
		cout << '#' << test_case << ' ' << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
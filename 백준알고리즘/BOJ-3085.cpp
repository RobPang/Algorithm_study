//사탕게임 - 구현, 브루트포스 알고리즘
#include <iostream>
#include <algorithm>
int N;
char Bomboni[50][50];
int Max_count = 0;
int count;

void Find_Max(char(*ptr)[50]) {
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 1; j < N; j++) {
			if (ptr[i][j - 1] == ptr[i][j]) {
				count++;
			}
			else {
				if (Max_count < count) Max_count = count;
				count = 1;
			}

		}
		if (Max_count < count) Max_count = count;
	}
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 1; j < N; j++) {
			if (ptr[j - 1][i] == ptr[j][i]) {
				count++;
			}
			else {
				if (Max_count < count) Max_count = count;
				count = 1;
			}

		}
		if (Max_count < count) Max_count = count;
	}


}

void StartBomboni() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (Bomboni[i][j] != Bomboni[i][j + 1]) {
				std::swap(Bomboni[i][j], Bomboni[i][j + 1]);
				Find_Max(Bomboni);
				std::swap(Bomboni[i][j], Bomboni[i][j + 1]);

			}
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (Bomboni[i][j] != Bomboni[i + 1][j]) {
				std::swap(Bomboni[i + 1][j], Bomboni[i][j]);

				Find_Max(Bomboni);
				std::swap(Bomboni[i + 1][j], Bomboni[i][j]);

			}
		}
	}
}

int main() {
	std::cin.tie(NULL);	// 시간 줄이기용
	std::ios::sync_with_stdio(false);	// 시간 줄이기용 - 버퍼를 비워준다

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> Bomboni[i][j];
		}
	}
	StartBomboni();

	std::cout << Max_count;
}
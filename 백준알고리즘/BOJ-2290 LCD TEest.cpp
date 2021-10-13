//LCD Test - 귀찮다, output의 결과를 잘 확인하자
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char LCD[24][130];


void print_0(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start] = '|';
		for (int i = 1; i <= s; i++) {
			LCD[j][start + i] = ' ';
		}
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 0; i <= s + 1; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = ' ';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄
		LCD[j][start] = '|';
		for (int i = 1; i <= s; i++) {
			LCD[j][start + i] = ' ';
		}
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = '-';
	}

}

void print_1(int s, int index) {
	int start = (s + 2)*index+ index;

	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start + s + 1] = '|';
	}

	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄
		LCD[j][start + s + 1] = '|';
	}

}
void print_2(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = '-';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄
		LCD[j][start] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = '-';
	}

}
void print_3(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = '-';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = '-';
	}

}
void print_4(int s, int index) {
	int start = (s + 2)*index+ index;

	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start] = '|';
		for (int i = 1; i <= s; i++) {
			LCD[j][start + i] = ' ';
		}
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = '-';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄

		LCD[j][start + s + 1] = '|';
	}


}
void print_5(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start] = '|';

	}
	for (int i = 1; i <= s; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = '-';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄

		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = '-';
	}

}
void print_6(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start] = '|';

	}
	for (int i = 1; i <= s; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = '-';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄
		LCD[j][start] = '|';
		for (int i = 1; i <= s; i++) {
			LCD[j][start + i] = ' ';
		}
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = '-';
	}

}
void print_7(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄

		LCD[j][start + s + 1] = '|';
	}
	for (int i = 0; i <= s + 1; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = ' ';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄

		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = ' ';
	}

}
void print_8(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start] = '|';
		for (int i = 1; i <= s; i++) {
			LCD[j][start + i] = ' ';
		}
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = '-';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄
		LCD[j][start] = '|';
		for (int i = 1; i <= s; i++) {
			LCD[j][start + i] = ' ';
		}
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = '-';
	}

}
void print_9(int s, int index) {
	int start = (s + 2)*index+ index;
	for (int i = 1; i <= s; i++) {		// 0번째 줄
		LCD[0][start + i] = '-';
	}
	for (int j = 1; j <= s; j++) {		// 1~s 번째 줄
		LCD[j][start] = '|';
		for (int i = 1; i <= s; i++) {
			LCD[j][start + i] = ' ';
		}
		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		// s+1번째 줄
		LCD[s + 1][start + i] = '-';
	}
	for (int j = s + 2; j <= s + 1 + s; j++) {	// s+2 ~ 2S+1 번째 줄

		LCD[j][start + s + 1] = '|';
	}
	for (int i = 1; i <= s; i++) {		//  2s +2 번째 줄
		LCD[s + s + 2][start + i] = '-';
	}

}


void printf_num(long long n,int s, int index) {
	if (n > 0) printf_num(n / 10, s, index-1);
	else if (n == 0) return;
	int prt = n % 10;
	switch (prt)
	{
	case 0 :
		print_0(s,index);
		break;
	case 1:
		print_1(s, index);
		break;
	case 2:
		print_2(s, index);
		break;
	case 3:
		print_3(s, index);
		break;
	case 4:
		print_4(s, index);
		break;
	case 5:
		print_5(s, index);
		break;
	case 6:
		print_6(s, index);
		break;
	case 7:
		print_7(s, index);
		break;
	case 8:
		print_8(s, index);
		break;
	case 9:
		print_9(s, index);
		break;

	}
}




int main() {
	int n; cin >> n;
	long long num;
	cin >> num;

	memset(LCD, ' ', sizeof(LCD));

	long long temp = num;
	int index = 0;
	while (temp > 0) {
		temp = temp / 10;
		index++;
	}

	printf_num(num,n,index-1);
	for (int i = 0; i < (2 * n + 3) ; i++) {
		for (int j = 0; j < (n + 2) *(index) + index -1; j++) {
			cout << LCD[i][j];
		}
		printf("\n");
	}
}
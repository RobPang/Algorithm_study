//하노이 탑 이동 순서 - 재귀 

#include <iostream>
#include <cmath>

void RunHanoi(int n, int from, int to, int pass);
int main() {
	int n; std::cin >> n;
	int32_t k;  // 장대를 옮긴 회수

	k = pow(2,n) - 1; // An = 2 * An-1 + 1
	printf("%d\n", k);

	RunHanoi(n, 1, 3, 2);

}
void RunHanoi(int n, int from, int to, int pass) {
	if (n == 1) printf("%d %d\n", from, to);
	else {
		RunHanoi(n - 1, from, pass, to);
		printf("%d %d\n", from, to);
		RunHanoi(n - 1, pass, to, from);
	}

}
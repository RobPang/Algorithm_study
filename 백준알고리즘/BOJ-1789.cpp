//수들의 합 - 수학, 그리디 알고리즘
#include <iostream>

using namespace std;
long long sum;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	cin >> sum;

	long long num = 1;
	long long temp = 0;

	while (1) {
		temp += num;
		if (temp > sum) {
			--num;
			break;
		}
		++num;
	}

	cout << num << "\n";
	return 0;
}

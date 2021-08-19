
// 결합법칙
#include <iostream> 
#include <vector>
#include <string>

int main() {
	std::string str;
	std::cin >> str;
	bool error_check = false;
	std::vector<char> Cal;
	int cnt1 = 0;
	int cnt2 = 0;

	int result=0;
	int temp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			temp = temp * 2;
			cnt1++;
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				result += temp;
			}
			cnt1--;
			temp = temp / 2;
		}
		else if (str[i] == '[') {
			temp = temp * 3;
			cnt2++;
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[') {
				result += temp;
			}
			cnt2--;
			temp = temp / 3;
		}
		if ((cnt1 < 0) | (cnt2 < 0)) {
			error_check = true;
		}
		if (error_check) break;
	}
	if ((cnt1 > 0) | (cnt2 > 0)) {
		error_check = true;
	}
	if (error_check) result = 0;
	printf("%d", result);

}
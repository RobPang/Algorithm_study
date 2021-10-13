//CPU - getline함수 및 string 다루기
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//int oper[501];
//if (temp == "ADD") oper[i] |= 0;
//else if (temp == "SUB") oper[i] |= (1 << (15 - 3));
//else if (temp == "MOV") oper[i] |= (1 << (15 - 2));
//else if (temp == "AND") oper[i] |= (1 << (15 - 3)) | (1 << (15 - 2));
//else if (temp == "OR") oper[i] |= (1 << (15 - 1));
//else if (temp == "NOT") oper[i] |= (1 << (15 - 1)) | (1 << (15 - 3));
//else if (temp == "MULT") oper[i] |= (1 << (15 - 1)) | (1 << (15 - 2));
//else if (temp == "LSFTL") oper[i] |= (1 << (15 - 2)) | (1 << (15 - 3)) | (1 << (15 - 1));
//else if (temp == "LSFTR") oper[i] |= (1 << (15 - 0));
//else if (temp == "ASFTR") oper[i] |= (1 << (15 - 0)) | (1 << (15 - 3));
//else if (temp == "RL") oper[i] |= (1 << (15 - 0)) | (1 << (15 - 2));
//else if (temp == "RR") oper[i] |= (1 << (15 - 0)) | (1 << (15 - 2)) | (1 << (15 - 3));

string oper[501];
int rd[501];
int ra[501];
int rb[501];  //constant 포함
bool c[501];

void printbit(int num, int n) {
	if (n>1) printbit(num >> 1,n-1);
	printf("%d", num&1);
}

int main() {
	int n; cin >> n;
	string input[501];

	for (int i = 0; i <= n; i++) {
		getline(cin, input[i]);
	}
	int mode = 0;
	for (int i = 1; i <= n; i++) {
		mode = 0;
		string temp;
		int num = 0;
		temp.clear();
		for (int j = 0; j < input[i].size(); j++) {
			
			if (input[i][j] == ' ') {
				if (mode == 0) {
					if (temp.back() == 'C') {
						c[i] = true;
						temp.erase(temp.end()-1);
					}
					if (temp == "ADD") oper[i] = "0000";
					else if (temp == "SUB") oper[i] = "0001";
					else if (temp == "MOV") oper[i] = "0010";
					else if (temp == "AND") oper[i] = "0011";
					else if (temp == "OR") oper[i] = "0100";
					else if (temp == "NOT") oper[i] = "0101";
					else if (temp == "MULT") oper[i] = "0110";
					else if (temp == "LSFTL") oper[i] = "0111";
					else if (temp == "LSFTR") oper[i] = "1000";
					else if (temp == "ASFTR") oper[i] = "1001";
					else if (temp == "RL") oper[i] = "1010";
					else if (temp == "RR") oper[i] = "1011";
				}
				else if (mode == 1) {
					rd[i] = num;
				}
				else if (mode == 2) {
					ra[i] = num;
				}
				

				num = 0;
				mode++;
				continue;
			}
			if (mode == 0) {
				temp += input[i][j];
			}
			else {
				num = num * 10 + input[i][j] - 48;
			}
			if(j == input[i].size() - 1) {
				if (mode == 3) {
					rb[i] = num;
				}
			}

		}

	}

	for (int i = 1; i <= n; i++) {
		cout << oper[i];
		if (c[i]) {
			printf("10");
		}
		else {
			printf("00");
		}
		printbit(rd[i],3);
		printbit(ra[i],3);

		if (c[i]) {
			printbit(rb[i], 4);
			printf("\n");
		}
		else {
			printbit(rb[i], 3);
			printf("0\n");
		}
	}


}

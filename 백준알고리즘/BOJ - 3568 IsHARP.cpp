// 왜 틀렸는지 모르겠다
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

char str[121];

int main() {

	string type;
	cin >> type;

	int index = 0;
	char input = 0;

	queue<string> q[2];
	string temp;
	string temp2;
	while (input != ';') {
		
		cin >> input;
		if ((input == ',' || input == ';')) {
			q[0].push(temp);
			q[1].push(temp2);
			temp.clear();
			temp2.clear();
		}
		else {
			if (input == '[') {
				temp2 += ']';
			}
			else if (input == ']') {
				temp2 += '[';
			}
			else if (input == '*') {
				temp2 += '*';
			}
			else if (input == '&') {
				temp2 += '&';
			}
			else {
				temp += input;
				index++;
			}
		}

	}

	while (!q[0].empty()) {
		string name;
		string opper;
		string output;
		opper = q[1].front();
		name = q[0].front();
		q[0].pop();
		q[1].pop();
		
		output = type;

		for (int i = opper.size(); i >= 0; --i) {
			output += opper[i];
		}
		output += ' ' + name + ';';
		cout << output << '\n';
	}


}
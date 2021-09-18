//가르침 - dfs, bitmasking 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//vector<string> str;
//vector<string> temp;

int n, k;
int str[50];
int alpha[27] = { 0 };
vector<int> checkbit;
vector<int> comparebit;
int bit = 0x00;

void DFS(int idx, int cnt) {
	if (cnt == k-5) {
		
		for (int i = 0; i < k-5; i++) {
			bit |= (1 << alpha[i]);
		}
		checkbit.push_back(bit);
		bit = (1 << 0) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));
		return;
	}
	for (int i = idx; i < 26; i++) {
		if ((bit & (1 << i)) == 0)
		{
			alpha[cnt] = i;
			DFS(i + 1, cnt + 1);
		}
	}
}

int main() {
	cin >> n >> k;
	
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			str[i] |= (1 << (temp[j] - 'a'));
		}
	}

	if (k < 5)
	{
		cout << 0 << endl;
		exit(0);
	}
	bit = (1 << 0) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));

	DFS(0, 0);

	int result = 0;
	for (int i = 0; i < checkbit.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if ((checkbit.at(i) & str[j]) == str[j]) {
				cnt++;
			}
		}
		result = max(result, cnt);
	}


	cout << result << '\n';
}

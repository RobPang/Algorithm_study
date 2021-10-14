//연산자 끼워넣기 - 브루트포스 알고리즘 백트레킹
#include <iostream>
int N; 
int Max = -1000000000;
int Min = 10000000000;
int ArrNum[11];
int ArrCal[4];

void Calculator(int result, int index){
    if(index == N){
        if(result > Max) Max = result;
        if(result < Min) Min = result;
        return ;
    }
    for(int i = 0 ; i< 4; i++){
        if(ArrCal[i]>0){
            ArrCal[i]--;
            switch(i){
                case 0:
                    Calculator(result+ArrNum[index],index+1);
                break;
                case 1:
                    Calculator(result-ArrNum[index],index+1);
                break;
                case 2:
                    Calculator(result*ArrNum[index],index+1);
                break;
                case 3:
                    Calculator(result/ArrNum[index],index+1);
                break;

            }
            ArrCal[i]++;
        }

    }

    return;
}

int main(){
    std::cin>>N;

    for(int i =0; i<N; i++){
        std::cin >> ArrNum[i];
    }
    std::cin >> ArrCal[0];
    std::cin >> ArrCal[1];
    std::cin >> ArrCal[2];
    std::cin >> ArrCal[3];
    Calculator(ArrNum[0],1);
    std::cout << Max << '\n';
    std::cout << Min ;

}

#include <iostream>

using namespace std;

long long big;
long long small;
int a[101];
int oper[4];
int n;

void dfs(int idx, int plus, int minus, int cross, int div, long long answer) {
	if (plus < 0 || minus < 0 || cross < 0 || div < 0) return ;
	if (idx == n -1) {
		if (big < answer) big = answer;
		if (small > answer) small = answer;
		return;
	}
	long long temp = answer + a[idx+1];
	dfs(idx + 1, plus - 1, minus, cross, div, temp);
	temp = answer - a[idx + 1];
	dfs(idx + 1, plus , minus - 1, cross, div, temp);
	temp = answer * a[idx + 1];
	dfs(idx + 1, plus , minus, cross -1, div, temp);
	temp = answer / a[idx + 1];
	dfs(idx + 1, plus , minus, cross, div -1, temp);



}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	big = -1000000000;
	small = 1000000000;

	dfs(0, oper[0], oper[1], oper[2], oper[3], a[0]);

	cout << big << '\n';
	cout << small << '\n';

}
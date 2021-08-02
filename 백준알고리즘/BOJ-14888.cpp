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

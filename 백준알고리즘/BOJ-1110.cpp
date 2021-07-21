// 더하기 사이클

#include <iostream>

int main (){

    int num; std::cin >> num;
    
    int num_1;
    int num_10;
    int temp;
    int cycle_cnt = 0;
    temp = num;
    while(1){
        num_1 = temp %10;
        num_10 = temp /10;
        temp = (num_1+num_10)%10+ num_1*10 ; 
        cycle_cnt++;
        if(temp == num) break;
    }

    std::cout << cycle_cnt;

}
// 한수
#include <iostream>

bool Find_Hansu(int num);

int main (){
    int receive_num;
    int result;

    std::cin >> receive_num;

    if(receive_num > 0 && receive_num <100) result = receive_num;
    else {
        result = 99;
        for(int i = 100; i  <= receive_num ; i++) {
            if(Find_Hansu(i)) result++;
        }
    }
    std::cout << result ;
}

bool Find_Hansu(int num) {
    int num_100;
    int num_10;
    int num_1;
    
    num_100 = num/100;
    num_10  = (num%100)/10;
    num_1   = num%10;

    if(num_10 - num_100 == num_1 - num_10) {return true;}
    else {return false;}  

}
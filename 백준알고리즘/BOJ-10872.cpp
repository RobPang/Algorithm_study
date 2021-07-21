//팩토리얼
#include <iostream>
int recursive(int num);
int main() {
    int num; std::cin>>num;
    int result = 1;

    std::cin.tie(NULL);	// 시간 줄이기용
	std::ios::sync_with_stdio(false);	// 시간 줄이기용 - 버퍼를 비워준다

    // 재귀 사용 x  문제 없음
    // for(int i = num; i>0 ; i--) {
    //     result *= i;
    // }


    // 재귀함수 사용  - 시간 초과
    result = recursive(num);
    
    std::cout << result;
}

//재귀함수
int recursive(int num) {
    if(num == 1){
        return 1;
    }
    return num* recursive(num -1);
}

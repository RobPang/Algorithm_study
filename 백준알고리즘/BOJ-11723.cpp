//집합 - 구현, 비트마스킹

#include <iostream>

bool Set[20] ={0};
void Add(int num);
void Remove(int num);
void Check(int num);
void Toggle(int num);
void All();
void Empty();

int main() {
    std::cin.tie(NULL);	// 시간 줄이기용
	std::ios::sync_with_stdio(false);	// 시간 줄이기용 - 버퍼를 비워준다
    
    int cal_num; std::cin >> cal_num;
    std::string  Calculate;
    int num;
    for(int i = 0; i<cal_num;i++){
        std::cin >> Calculate;
        if(Calculate == "add"){
            std::cin >> num;
            Add(num-1);
        }
        else if(Calculate == "remove"){
            std::cin >> num;
            Remove(num-1);
        }
        else if(Calculate == "check"){
            std::cin >> num;
            Check(num-1);
        }
        else if(Calculate == "toggle"){
            std::cin >> num;
            Toggle(num-1);
        }
        else if(Calculate == "all"){
            All();
        }
        else if(Calculate == "empty"){
            Empty();
        }
        else{

        }
    }
}

void Add(int num) {
    Set[num] = true;
}
void Remove(int num) {
    Set[num] = false;
}
void Check(int num) {
    if(Set[num]){
      std::cout << 1 << "\n";
    }
    else {
      std::cout << 0 << "\n";
    }
}
void Toggle(int num) {
    //if(Set[num]) Set[num] = false;
    //else Set[num] = true;
    Set[num] = !Set[num];
}
void All() {
    for(int i = 0; i <20 ; i++){
        Set[i] = true;
    }
}
void Empty() {
    for(int i = 0; i <20 ; i++){
        Set[i] = false;
    }
}
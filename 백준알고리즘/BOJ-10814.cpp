//정렬 나이순 정렬
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Info_Member {
    public:
        int _age = 0;
        std::string _name = "";
    Info_Member(int age, std::string name) {
        _age = age; 
        _name = name;
    } 
};

//age만 비교하는 함수
bool Compare(Info_Member a, Info_Member b);

int main() {

    int num;
    int age;
    std::string name;
    std::cin >> num;

    std::vector<Info_Member> DB;

    for(int i = 0; i < num; i++) {
        std::cin >> age;
        std::cin >> name;
        DB.push_back(Info_Member(age,name));
    }

    stable_sort(DB.begin(), DB.end(),Compare);

    for(int i = 0; i < num; i++) {
        std::cout << DB.at(i)._age << " " <<DB.at(i)._name << '\n';
    }


}
bool Compare(Info_Member a, Info_Member b) {
    return a._age < b._age;
}

/*
//  다른사람이 사용한 queue를 사용한 코드
*/

#include <iostream>
#include <queue>
using namespace std;

queue<string> age[201];

int main()
{
	int N; cin >> N;
	int num;
	string st;
	for (int i = 0; i < N; i++) {
		cin >> num >> st;
		age[num].push(st);
	}
	for (int i = 1; i <= 200; i++) {
		while (!age[i].empty()) {
			cout << i << ' ' << age[i].front() << '\n';
			age[i].pop();
		}
	}
}
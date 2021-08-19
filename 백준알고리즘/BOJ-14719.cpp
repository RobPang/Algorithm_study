// // 구현, 시뮬레이션
// #include <iostream>
// //#include <math.h>

// int main() {

// 	std::cin.tie(NULL);	// 시간 줄이기용
// 	std::ios::sync_with_stdio(false);	// 시간 줄이기용 - 버퍼를 비워준다

// 	int h, w;
// 	std::cin >> h >> w;
// 	int Arr[500] = { 0 };
// 	int ptr1, gijun1;
// 	ptr1 = 0;
// 	int ptr2, gijun2;
// 	ptr2 = w - 1;
// 	int sum1 = 0, sum2 = 0;
// 	int result = 0;
// 	for (int i = 0; i < w; i++) {
// 		std::cin >> Arr[i];
// 	}

// 	gijun1 = Arr[0];
// 	gijun2 = Arr[w - 1];




// 	while (1) {
// 		int temp1 = 0;
// 		int temp2 = 0;
// 		sum1 = 0, sum2 = 0;
//         static bool flag1 = true;
//         static bool flag2 = true;
// 		for (int i = ptr1; ; i++) {
// 			if(flag1){
//                 if (Arr[i] > gijun1) {
//                     gijun1 = Arr[i];
//                     ptr1 = i;
//                     sum1 = temp1;
//                     break;
//                 }
//                 else {
//                     if (gijun1 - Arr[i] > 0) temp1 += (gijun1 - Arr[i]);
//                 }
//                 if (i == ptr2 ){
//                     flag1 = false;
//                     break;
//                 }
//             }
            
// 		}

// 		for (int j = ptr2; ; j--) {
//             if(flag2){
//                 if (Arr[j] > gijun2) {
//                     gijun2 = Arr[j];
//                     ptr2 = j;
//                     sum2 = temp2;
//                     break;
//                 }
//                 else {
//                     if (gijun2 - Arr[j] > 0) temp2 += (gijun2 - Arr[j]);
//                 }
//                 if (j == ptr1){
//                     flag2= false;
//                 break;  
//                 }
//             } 
// 		}

// 		if (ptr1 > ptr2) {
// 			result += sum1;
// 			break;
// 		}
// 		else if (ptr1 == ptr2) {
// 			result += (sum1 + sum2);
// 			break;
// 		}
// 		else {
// 			result += (sum1 + sum2);
// 		}

// 	}
// 	printf("%d", result);
// }
// 예제 코드는 되는데 시간 초과 나중에 다시 생각해보자

#include <iostream>


int max(int A, int B) { return A > B ? A : B; }
int min(int A, int B) { return A < B ? A : B; }


int main() {
    int h, w;
    int result = 0;
    int Arr[500];
    std::cin >> h>> w;

    for(int i = 0; i<w ; i++){
        std::cin >> Arr[i];
    }

    for(int i =1; i< w-1 ; i++){
        int left_max =0; int rigth_max = 0;
        for(int j = 0; j< i ; j++) {
            left_max = max(left_max, Arr[j]);
        }
        for(int j = w-1; j>i ; j--) {
            rigth_max = max(rigth_max, Arr[j]);
        }

        result += max(0, min(left_max,rigth_max) - Arr[i]);
    }
    std::cout << result;
}
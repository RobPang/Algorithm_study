//동전2 - 동적프로그래밍

#include <iostream>
#include <algorithm>
//#include <vector>
using namespace std;

//#define min(a,b)  ((a < b) ? (a) : (b))
int n , k;
int arr[100];
int dp[10001]; 

int main(){
    // 시간 줄여준다고 해서 사용했는데 오히려 정답에 영향을 줘서 쓰기 꺼려짐
//    ios::sync_with_stdio(false);
//    cout.tie(NULL);
//    cin.tie(NULL);

  
    scanf("%d %d", &n, &k);
 

    for(int i = 0; i < n; i++) {
        cin>> arr[i];
    }
    fill(dp, dp+10001, 10001);
    dp[0] = 0;
    for(int i = 0; i< n; i++){
        for(int j = arr[i]; j <= k; j++){
            dp[j] = min(dp[j], dp[j - arr[i]]+1);
        }
    }
    dp[k] = (dp[k] == 10001) ? -1: dp[k];
    cout << dp[k] << '\n';
    return 0;
}
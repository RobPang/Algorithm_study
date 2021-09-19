//A->B BFS greed
#include <iostream>
#include  <queue>

using namespace std;

int cnt[1000000001];
int result;
void bfs(long long start, long long end){
    queue<int> q;
    q.push(start);
    cnt[start] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == end){
            result = cnt[x];
            break;
        }
        for(int i = 0 ; i < 2 ; i++){
            if(i == 0 ){
                int y = x*10 +1;
                cnt[y] = cnt[x]+1;
                if(y <= end){
                    q.push(y);
                }
            }
            else{
                int y = x*2;
                cnt[y] = cnt[x]+1;
                if(y <= end){
                    q.push(y);
                }
            }
        }
    }
    
}


int main(){
    long long  n, k ; cin >> n >> k;
    result = -1;
    bfs(n,k);
    cout << result;

}
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define MAx 9999999999

int dist[200000];

void bfs(int start, int end) {
    deque<int> dq;
    dq.push_back(start);
    dist[start] = 0;
    while(dq.size()){
        int x = dq.front();
        dq.pop_front();

        if(x == end){
            cout << dist[x];
            return;
        }
        int y = x*2;
        if(y<=200000 && dist[y] > dist[x]){
            dist[y] = dist[x];
            dq.push_front(y);
        }
        y = x +1;
        if(y <=end && dist[y] > dist[x]+1){
            dist[y] = dist[x] +1;
            dq.push_back(y);
        }
        y= x-1;
        if(y >= 0 && dist[y] > dist[x]+1){
            dist[y] = dist[x] +1;
            dq.push_back(y);
        }

    }

}


int main() {
    int n, k;
    cin >> n >> k;
    bfs(n,k);
}
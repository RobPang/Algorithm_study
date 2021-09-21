#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[200001];

void bfs(int start, int end) {
    queue<vector<int>> q;
    vector<int> v;
    v.push_back(start);
    q.push(v);
    check[start] = true;
    while(!q.empty()){
        vector<int> x = q.front();
        int cur = x.back();
        q.pop();
        check[cur] = true;
        if(cur == end){
            cout << x.size()-1 << '\n';
            for(int i = 0; i < x.size(); i++){
                cout << x.at(i) << ' ';
            }
            break;
        }

        vector<int> y = x;
        int next = cur*2;
        if(next < 200000 &&!check[next]){
            y.push_back(next);
            q.push(y);
            y.pop_back();
        }
        next = cur+1;
        if(next<=end && !check[next]){
            y.push_back(next);
            q.push(y);
            y.pop_back();
        }
        next = cur-1;
        if(next>=0 && !check[next]){
            y.push_back(next);
            q.push(y);
            y.pop_back();
        }
    }

}

int main() {
    int n ,k;
    cin >> n >> k;

    bfs(n,k);
    
}


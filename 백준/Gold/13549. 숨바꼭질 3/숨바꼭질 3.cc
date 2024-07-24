#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int n,k;
int visited[MAX+1]={};

void bfs(){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.emplace(0,n);
    visited[n]=1;

    while(!pq.empty()){
        int cur=pq.top().second;
        int time=pq.top().first;
        pq.pop();

        visited[cur]=1;

        if(cur==k){
            cout << time;
            return;
        }

        if( 2*cur <= MAX && !visited[2*cur]){
            pq.emplace(time,2*cur);
            visited[2*cur]=1;

        }

        if( cur+1 <= MAX && !visited[cur+1]){
            pq.emplace(time+1,cur+1);
            visited[cur+1]=1;

        }

        if( cur-1 >= 0 && !visited[cur-1]){
            pq.emplace(time+1,cur-1);
            visited[cur-1]=1;
        }

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    bfs();

}
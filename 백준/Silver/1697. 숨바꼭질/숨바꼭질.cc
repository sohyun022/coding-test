#include <iostream>
#include <queue>

using namespace std;

int n,k;

int visited[200001]={};
int t[200001]={};

queue<int> q;

void bfs(){
    q.push(n);
    visited[n]=1;
    t[n]=0;

    while(!q.empty()){
        int x=q.front(); //x=현재 위치
        q.pop();

        if(x==k){
            break;
        }

        if(x-1>=0 && !visited[x-1]){
            q.push(x-1);
            t[x-1]=t[x]+1;
            visited[x-1]=1;
        }

        if(x+1<=200000 && !visited[x+1]){
            q.push(x+1);
            t[x+1]=t[x]+1;
            visited[x+1]=1;
        }

        if(x*2<=200000 && !visited[x*2]){
            q.push(x*2);
            t[x*2]=t[x]+1;
            visited[x*2]=1;
        }

    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    bfs();

    cout << t[k];

}
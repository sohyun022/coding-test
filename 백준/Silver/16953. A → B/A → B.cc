#include <iostream>
#include <queue>
#include <unordered_map>
int a,b;

using namespace std;
unordered_map<int, int> graph;

int bfs(){
    queue<int> q;
    q.push(a);
    graph[a]=1;

    while(!q.empty()){
        long i=q.front();
        q.pop();

        if(i==b) return graph[b];

        if(i*2<=b){
            q.push(i*2);
//            cout << i*2 <<endl;
            graph[i*2]=graph[i]+1;
        }

        if(i*10+1<=b){
            q.push(i*10+1);
//            cout << i*10+1<<endl;
            graph[i*10+1]=graph[i]+1;
        }

    }
    return -1;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    cout << bfs();

}
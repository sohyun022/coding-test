#include <iostream>
#include <queue>
using namespace std;

int n,m;
int visited[1001]={};
int graph[1001][1001]={};

queue <int> q;

void bfs(int i){
    q.push(i);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        visited[x]=1;

        for(int j=1;j<=n;j++){
            if(!visited[j] && graph[x][j]==1){
                q.push(j);
                visited[j]=1;
            }
        }
    }


}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int a,b;

    for(int i=0;i<m;i++){
        cin >> a >> b;

        graph[a][b]=1;
        graph[b][a]=1;

    }

    int count=0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(i);
            count++;
        }
    }

    cout << count;

}
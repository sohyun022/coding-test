#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n,m;
int a,b;

int graph[1000][1000]={};
int route[1000][1000]={};
int visited[1000][1000]={};

void bfs(){

    queue<pair<int,int>> q;
    q.emplace(a,b);
    graph[a][b]=0;

    while(!q.empty()){

        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        visited[x][y]=1;

        for(int k=0;k<4;k++){
            int X=x+dx[k];
            int Y=y+dy[k];

            if(X>=0 && X<n && Y>=0 && Y<m && !visited[X][Y] && graph[X][Y]==1){
                visited[X][Y]=1;
                route[X][Y]=route[x][y]+1;
                q.emplace(X,Y);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(route[i][j]==0)
                route[i][j]=-1;
            if(graph[i][j]==0)
                route[i][j]=0;
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
            if(graph[i][j]==2){
                a=i;
                b=j;
            }
        }
    }

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << route[i][j] << " ";
        }
        cout << endl;
    }
}

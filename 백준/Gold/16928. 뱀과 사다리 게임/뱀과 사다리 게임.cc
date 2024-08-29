#include <iostream>
#include <queue>

using namespace std;

int n,m;

int ladder_snake[101]={};

int visited[101]={};

void bfs(int c){

    queue<int> q;
    q.push(c);

    while(!q.empty()){

        int cur=q.front();
        q.pop();

        if(cur==100){
            return;
        }

        for(int i=1;i<=6;i++){

            int next=cur+i;

            if (next > 100) continue;

            if(ladder_snake[next]){
                next=ladder_snake[next];
            }

            if(!visited[next]){
                visited[next]=visited[cur]+1;
                q.push(next);
            }

        }

    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=0;i<n+m;i++){
        int start,end;
        cin >> start >> end;
        ladder_snake[start]=end;
    }

    bfs(1);

    cout << visited[100];

}
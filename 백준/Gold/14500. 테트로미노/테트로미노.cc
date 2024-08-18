#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<int>> graph;
int visited[500][500]={};

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int maxSum=0;

void dfs(int i,int j,int depth,int sum){

    if(depth==4){
        if(sum>maxSum){
            maxSum=max(sum,maxSum); 
        }
        return;
    }

    for(int k=0;k<4;k++){
        if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m){

            int x=i+dx[k];
            int y=j+dy[k];

            if(!visited[x][y]){
                visited[x][y]=1;
                dfs(x,y,depth+1,sum+graph[x][y]); //백 트랙킹 후 이전 sum 값이 복원 되도록 인자를 넘김
                visited[x][y]=0;
            }
        }
    }
}

void check(int i,int j){
    
    if(i+1 <n && j+2 <m){ // ㅜ 
        maxSum=max(graph[i][j] +graph[i][j+1]+ graph[i][j+2]+graph[i+1][j+1],maxSum);
    }

    if(i+2 <n && j+1 <m){ // ㅏ 
        maxSum=max(graph[i][j] +graph[i+1][j]+ graph[i+2][j]+graph[i+1][j+1],maxSum);
    }

    if(j-1 >=0 && i+1 <n && j+1 <m){ // ㅗ 
        maxSum=max(graph[i][j] +graph[i+1][j-1]+ graph[i+1][j]+graph[i+1][j+1],maxSum);
    }

    if(j-1 >=0 && i+2 <n){ //ㅓ
        maxSum=max(graph[i][j] +graph[i+1][j-1]+ graph[i+1][j]+graph[i+2][j],maxSum);
    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.resize(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=1;
            dfs(i,j,1,graph[i][j]);
            visited[i][j]=0;
            check(i,j); // ㅏ, ㅗ, ㅜ, ㅓ 모양 테트로미노 탐색
        }
    }

    cout << maxSum;
}
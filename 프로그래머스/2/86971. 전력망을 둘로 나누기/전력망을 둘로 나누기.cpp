#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int graph[101][101]={};
int cnt;
int h;

void dfs(int node,int visited[]){
    visited[node]=1;
    cnt++;
    
    for(int j=1;j<=h;j++){ // node와 연결된 이웃 노드
        if(!visited[j] && graph[node][j]==1){
            dfs(j,visited);     
        }   
    }
}



int solution(int n, vector<vector<int>> wires) {
    
    // 인접 행렬 만들기
    for(auto wire : wires){
        graph[wire[0]][wire[1]]=1;
        graph[wire[1]][wire[0]]=1;
    }
    
    h=n;
    
    int sub = 100;
    
    for(auto wire : wires){
        
        // 와이어 자르기
        graph[wire[0]][wire[1]]=0;
        graph[wire[1]][wire[0]]=0;
        
        // 와이어가 잘린 두 노드
        int a = wire[0];
        int b = wire[1];
        
        int visited[101]={};
        
        cnt=0;
        dfs(a,visited); // a와 연결된 노드의 개수 찾기
        int cnta = cnt;
        
        cnt=0;
        dfs(b,visited); // b와 연결된 노드의 개수 찾기
        int cntb =cnt;
        
        cout << cnta << " " << cntb << endl;
        
        sub = min(sub,abs(cnta-cntb)); // 노드 개수의 차의 최소값
        
        graph[wire[0]][wire[1]]=1;
        graph[wire[1]][wire[0]]=1;
    }
    
    return sub;
}
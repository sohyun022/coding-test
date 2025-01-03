#include <vector>
#include <queue>

using namespace std;
int visited[200]={};
int n;
vector<vector<int>> computers;
queue<int> q;

void bfs(){
    
    while(!q.empty()){
        
    int i =q.front();
        q.pop();
        
        for(int j=0;j<n;j++){
            if(computers[i][j]==1 && !visited[j]){
                q.push(j);
                visited[j]=1;
            }   
        }
    } 
}

int solution(int N, vector<vector<int>> COMPUTERS) {
    
    computers=COMPUTERS;
    n=N;
    
    int answer = 0;
    
    for(int k=0;k<n;k++){
        if(!visited[k]){
            visited[k]=1;
            q.push(k);
            bfs();
            answer++;
           }
       }
    
    return answer;
}
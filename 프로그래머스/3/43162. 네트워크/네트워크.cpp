#include <string>
#include <vector>

using namespace std;
int visited[200]={};
int n;
vector<vector<int>> computers;

void dfs(int i){
    for(int j=0;j<n;j++){
        if(computers[i][j]==1 && !visited[j]){
            visited[j]=1;
            dfs(j);   
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
            dfs(k);
            answer++;
           }
       }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;



int solution(int n, vector<vector<int>> edge) {
    
    int answer=0;
    
    vector<vector<int>> graph(n+1);
    
    vector<int> visited(n+1,0);
    
    vector<int> dist(n+1);
    
    for(auto e : edge){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    
    q.push(1);
    dist[1]=0;
    visited[1]=1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(auto node : graph[cur]){
            if(!visited[node]){
                q.push(node);
                dist[node]=dist[cur]+1;  
                visited[node]=1;
            }
            
        }
    }
    
    int maxDist = *max_element(dist.begin(),dist.end());
    
    for(int i =1;i<=n ;i++){
        if(dist[i] == maxDist)
            answer++;
    }
    cout << maxDist;
    return answer;
    
    
}
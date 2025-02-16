#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int n;

vector<string> result;

void dfs(string dept, unordered_map<string, map<string,int>>& map, vector<string>& answer,int cnt){
    
    answer.push_back(dept);
    
    if(cnt == n+1){
        result = answer;
        return;
    }
    
    for( auto& dest : map[dept]){ 
        
        string dstn = dest.first;
        int& count = dest.second;
        
        if(count > 0){
            count--;
            dfs(dstn,map,answer,cnt+1);
            
            if(!result.empty()) 
                return;
            
            count++;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    unordered_map<string, map<string,int>> map;
    vector<string> answer;
    
    for( auto ticket : tickets ){
        map[ticket[0]][ticket[1]]+=1;
    }
    
    n = tickets.size();
    
    dfs("ICN",map,answer,1);
    
    return result;
      
}
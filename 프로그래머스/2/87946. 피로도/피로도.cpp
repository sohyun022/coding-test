#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int length;
int cnt=0;
vector<vector<int>> ds;

void expl_dungeon(int k,int depth,int count){
    
    if(depth == length){
        cnt = max(count,cnt);
        return;
    }
        
    if(k >= ds[depth][0]){
        expl_dungeon(k-ds[depth][1],depth+1,count+1);  
    }
    
    expl_dungeon(k,depth+1,count);
         
}

bool compare(vector<int> a, vector<int> b){
    return a[0]-a[1] > b[0]-b[1];
}

int solution(int k, vector<vector<int>> dungeons) {
    
    ds = dungeons;
    length = dungeons.size();
    
    sort(ds.begin(),ds.end(),compare);
    
    expl_dungeon(k,0,0);
    
    if(cnt == 0 ) return -1;
    
    return cnt;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue<int,vector<int>,greater<int>> pq(scoville.begin(),scoville.end());
    
    //2 4 5 6 82 100 101
    
    int cnt=0;
    
    int firstS, secondS, newS ;
    
    while(!pq.empty()){
        
        if(pq.size() == 1 && pq.top() < K){
            return -1;
        }
        
        firstS = pq.top();
        pq.pop();
        
        if(firstS < K){
            secondS = pq.top();
            pq.pop();
            newS = firstS + secondS * 2;
            
            pq.push(newS);
            cnt++;
        }
        else
            return cnt;
    }
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

// 우선순위큐 두개를 만든다
// 값이 들어올 때마다 두 큐에 모두 삽입
// 최대/최소값을 삭제하는 경우 해당하는 큐에서 삭제
// 원소개수를 확인하고 삭제
using namespace std;

vector<int> solution(vector<string> operations) {
    
    priority_queue<int,vector<int>,less<int>> pql; //큰 값이 priority 큼
    priority_queue<int,vector<int>,greater<int>> pqg;
    unordered_map<int,int> map;
    
    vector<int> answer;
    
    int pqsize=0;
    
    for(auto oper: operations){
        if(oper[0]=='I'){
            int a = stoi(oper.substr(2));
            pql.push(a);
            pqg.push(a);
            pqsize++;
            map[a]++;
        }
        
        else if(oper.compare("D 1")==0 && pqsize > 0){
            while(!map[pql.top()] && !pql.empty())
                pql.pop();
            
            if(!pql.empty()){
                map[pql.top()]--;
                pql.pop();
                pqsize--;
                
            }  
        }
        
        else if(oper.compare("D -1")==0 && pqsize > 0 ){
            while(!pqg.empty() && !map[pqg.top()] )
                pqg.pop();
            
            if(!pqg.empty()){
                map[pqg.top()]--;
                pqg.pop();
                pqsize--;   
            }
        }
    }
    
    while(!pqg.empty() &&!map[pqg.top()] ){
        pqg.pop();
    }
    
    while( !pql.empty() && !map[pql.top()])
                pql.pop();
    
    if( pqg.empty() || pql.empty() ){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pql.top());
        answer.push_back(pqg.top());
    }

    return answer;
}
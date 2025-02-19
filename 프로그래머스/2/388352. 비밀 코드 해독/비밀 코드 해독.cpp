#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
int N;

vector<vector<int>> comb;
bool visited[31]={};
void combination(int index, int depth, vector<int>& secret){
    
    if(depth == 5){
        comb.push_back(secret);
        
        return;
    }
    
    for(int i=index+1 ;i <= N ;i++){    
        secret.push_back(i);
        combination(i,depth+1,secret);  
        secret.pop_back();
    }    
}

int compare(vector<int> a, vector<int> b){
    
    int cnt =0;
    
    for(int i=0; i< 5;i++){
        for(int j =0 ;j<5 ;j++){
            if(a[i]==b[j])
                cnt++;
        }
    }
    
    return cnt;
    
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    // 퍼뮤테이션으로 각 배열에서 정답 숫자 만큼을 뽑는다 
    // 모든 뽑은 숫자들을 set에 넣는다
    // set size =5이면 정답 개수 추가
    
    N = n;

    vector<int> secret;
    
    int answer=0;
    
    combination(0,0,secret);
    
    for ( auto code : comb ){
        int flag = true;
        
        for( int i =0 ;i < q.size() ; i++){
            if(compare(code,q[i])!=ans[i]){
                flag = false;
                break;
            }      
        }  
        
        if(flag == true)
            answer++;
    } 
    return answer;
}

// n까지 정수 5개 10 ~ 30
// m번의 시도 10번이하
// 몇개가 맞았는지 알려줌
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

queue<pair<string,int>> q; //string과 몇번째 과정에 해당하는 문자인지 저장
int visited[50]={}; //이미 한 번 과정에 포함된 string은 다시 고려하지 않음
const char * from; //변환 과정에 있는 문자
int l; //string 길이
int words_cnt; //string 개수

bool check(string word){
    int cnt=1;
    const char * to = word.c_str(); //from 다음에 올 수 있는지 확인될 문자
    
    for(int i = 0; i < l; i++){ //string에서 한 글자씩 비교
        if(from[i]!=to[i]){
            if(cnt == 0) //이미 다른 문자가 있었으면
                return false; //문자가 두 개이상 다름 -> false
            cnt--;
        }       
    }
    return true; //하나만 다른 경우 반복문을 빠져나옴 -> true return  
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    l = begin.size();
    from = begin.c_str();
    words_cnt = words.size();
    
    for(int s=0;s<words_cnt;s++){
        if(check(words[s])){ //시작 string(begin)과 비교함
            if(words[s].compare(target)==0)
                return 1;
            q.emplace(words[s],1);
            visited[s]=1;
        }
            
    }
 
    while(!q.empty()){
        
        from = q.front().first.c_str();
        int count = q.front().second;
        q.pop();
        
        for(int s=0;s<words_cnt;s++){
            if(!visited[s] && check(words[s])){
                if(words[s].compare(target)==0)
                    return count+1;
                q.emplace(words[s],count+1);
                visited[s]=1;
            }
        }       
    }
    
    return 0;
}
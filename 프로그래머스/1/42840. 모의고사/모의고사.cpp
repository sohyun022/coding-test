#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    int cnt[3]={};
  
    string first = "";
    string second = "";
    string third = "";
    
    while ( first.size() <= 10000 ){
        first += "123451234512345";
    }  
    while ( second.size() <= 10000 ){
        second += "2123242521232425";
    }  
    while ( third.size() <= 10000 ){
        third += "33112244553311224455";
    }  

    int length = answers.size();
    
    for(int i=0;i<length;i++){
        if( first[i]-'0' == answers[i])
            cnt[0]++;
        if( second[i]-'0' == answers[i])
            cnt[1]++;
        if( third[i]-'0' == answers[i])
            cnt[2]++;
    }
    
    vector<int> answer;
    int max_cnt = 0;
    
    for(int i=0;i<3;i++){
        max_cnt = max(max_cnt,cnt[i]);
    }
    
     
    for(int i=0;i<3;i++){
        if(cnt[i] == max_cnt)
            answer.push_back(i+1);
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(string word) {
    
    int answer=0;
    
    unordered_map<char,int> vowel;
    
    vowel['A']=0;
    vowel['E']=1;
    vowel['I']=2;
    vowel['O']=3;
    vowel['U']=4;
    
    int weight[]={781,156,31,6,1};
    
    for(int i=0;i<word.size();i++){
        answer += vowel[word[i]]*weight[i] +1;
    }
    
    return answer;
    
    
}
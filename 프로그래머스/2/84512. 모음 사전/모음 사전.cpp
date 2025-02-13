#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> words;

string vowels ="AEIOU";

void makeWord(string cur){
    
    if(cur.size() > 5)
        return;
    
    words.push_back(cur);
    
    for( char c : vowels){
        makeWord(cur+c);
    } 
        
}

int solution(string word) {
    
    int answer=0;
    
    makeWord("");
    
    for(int i=0;i<words.size();i++){
        if(word.compare(words[i])==0)
            return i;
    }  
}
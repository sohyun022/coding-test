#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int length = brown + yellow; 
    int width, height;
    int a = brown/2;
    
    vector<int> answer;
    
    for(int i=1;i<a;i++){
        int l = a - i;
        int w = i;
        
        if((l+1)*(w+1) == length){
            answer.push_back(l+1);
            answer.push_back(w+1);
            break;
        }  
    }
    
    return answer;
}
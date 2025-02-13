#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int first=0; //짧은 변
    int second=0; //긴 변
    
    for(auto size: sizes){
        
        sort(size.begin(),size.end()); //길이가 짧은 순으로 정렬
        
        if(size[0] > first && size[1] > second){
            first = size[0];
            second = size[1];
        }
        
        else if(size[0] <= first && size[1] > second){
            second = size[1];
        }
        
        else if(size[0] > first && size[1] <= second){
            first = size[0];
        }
    }
    
    return first*second;
}
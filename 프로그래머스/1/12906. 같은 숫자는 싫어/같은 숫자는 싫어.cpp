#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr){
    
    vector<int> answer;
    int index=arr[0];
    answer.push_back(index);
    
    for( auto& i : arr){
        if(i!=index)
            answer.push_back(i);
        index=i;
    }
    
    return answer;
}
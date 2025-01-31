#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int hIndex = 0;
    
    sort(citations.begin(),citations.end(),greater<int>());

    int n=citations.size();
   
    for(int i=0;i<n;i++){
        if(citations[i] >= i+1){
            hIndex=i+1;
        }
    }
    
    return hIndex;
}
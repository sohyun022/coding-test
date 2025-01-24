#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int hIndex = 0;
    
    sort(citations.begin(),citations.end());

    int n=citations.size();
    
    if(n<citations[0]){
        return n;    
    }
    
    for(int i=0;i<n;i++){
        if(citations[i]<= n-i){
            hIndex=citations[i];
            while(hIndex+1 <= n-i-1 )
                hIndex++;
        }
    }
    
    return hIndex;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    int n=progresses.size();
    vector<int> answer;
    
    int i=0;
    
    while(i<n){
        int count=0;
        int days=(100-progresses[i])/speeds[i];
        
        if((100-progresses[i])%speeds[i]!=0)
            days++;
        
    
        while (i < n && progresses[i] + speeds[i] * days >= 100) {
            i++;
            count++;
        }
        
        answer.push_back(count);
        
    }
    
    
    return answer;
}
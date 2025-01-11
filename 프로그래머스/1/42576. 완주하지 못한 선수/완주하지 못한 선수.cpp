#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string,int> parti;
map<string,int> comp;

string solution(vector<string> participant, vector<string> completion) {
    
    sort(completion.begin(),completion.end());
    sort(participant.begin(),participant.end());
    
    for(string p :participant){
        parti[p]++;
    }
    for(string c :completion){
        comp[c]++;
    }
    for(string p :participant){
        if(parti[p]!=comp[p])
            return p;
    }
    
    
    
}
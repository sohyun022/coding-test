#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(),phone_book.end());
    
    int s=phone_book.size();
    
    for(int i=0;i<s-1;i++){
        string sub=phone_book[i+1].substr(0,phone_book[i].length());
        if(phone_book[i].compare(sub)==0)
            return false;     
    }
    return true;
}
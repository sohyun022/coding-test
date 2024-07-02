#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    string name;
    cin >> name;
    unordered_map<char,int> map;

    string palindrome;

    int isOdd=0;

    for(char c: name){
        map[c]++;
    }
    char oddc;
    bool check=false;

    set<char> pal;

    for(char c: name){
        pal.insert(c);
    }

    for(char c : pal){
        if(map[c]%2){
            isOdd++;
            oddc=c;
            check=true;
        }
    }

    if(isOdd>1){
        cout << "I'm Sorry Hansoo";
    }

    else{
        for(char c: pal){
            for(int i=0;i<map[c]/2;i++){
                palindrome+=c;
            }
        }
        unsigned long l=palindrome.size();

        if(check){
            palindrome+=oddc;
        }

        for(int i=0;i<l;i++){
            palindrome+=palindrome[l-i-1];
        }

        cout << palindrome;

    }
}

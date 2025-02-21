#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> words(n);
    for(int i =0;i<n;i++){
        cin >> words[i];
    }

    int cnt =0;

    int sLen=s.length();
    while(cnt<26){

        for(int i =0;i<sLen;i++){
            if(s[i] == 'z')
                s[i]='a';
            else
                s[i]+=1;

        }

        for(auto word : words){
            int wordLen= word.length();

            for(int i =0; i<= sLen-wordLen; i++){
                string tmp;
                tmp = s.substr(i,wordLen);
                if(tmp == word){
                    cout << s;
                    return 0;
                }

            }
        }
        cnt++;
    }
}

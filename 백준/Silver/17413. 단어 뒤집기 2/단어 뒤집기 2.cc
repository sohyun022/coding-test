#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;

    getline(cin, str);

    unsigned long size=str.size();

    stack<char> s;

    for(int i=0;i<size;i++){
        if(str[i]=='<'){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }

            while(i< size && str[i]!='>'){
                cout  << str[i];
                i++;
            }
            cout << '>';
        }

        else if(str[i]==' '){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << ' ';
        }
        else
            s.push(str[i]);

    }

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

}
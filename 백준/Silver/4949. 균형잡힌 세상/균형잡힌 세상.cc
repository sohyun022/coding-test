#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {


    while(true){
        string str;
        getline(cin,str);
        stack<char> s;

        bool flag=false;

        if(str[0]=='.') break;


        for(int i=0;i<str.length();i++){
            if(str[i]=='(' || str[i]=='[')
                s.push(str[i]);

            else if(str[i]==')'){
                if(!s.empty() && s.top()=='(')
                    s.pop();
                else
                    flag=true;
            }

            else if(str[i]==']'){
                if(!s.empty() && s.top()=='[')
                    s.pop();
                else
                    flag=true;
            }

        }

        if(s.empty() && !flag){
            cout << "yes" <<endl;
        }
        else{
            cout << "no" << endl;
        }
    }

}

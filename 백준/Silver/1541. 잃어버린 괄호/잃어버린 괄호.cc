#include <iostream>
#include <string>

using namespace std;

int main() {
    string exp;
    cin >> exp;

    string num;

    int result=0;

    bool isMinus=false;

    for(char c: exp){


        if(c=='+' || c=='-'){
            if(isMinus){
                result-=stoi(num);
            }
            else{
                if(c=='-')
                    isMinus=true;
                result+=stoi(num);
            }
            num="";
        }

        else{
            num+=c;
        }

    }
    if(isMinus){
        result-=stoi(num);
    }
    else
        result+=stoi(num);

    cout << result;

}
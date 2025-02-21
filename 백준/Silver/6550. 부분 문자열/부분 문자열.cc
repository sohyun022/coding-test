#include <iostream>

using namespace std;

int main() {

    string s,t;

    while(cin >> s >> t){

        bool flag = false;
        int index =0;

        for(int i =0;i<t.length();i++){

            if(s[index]==t[i]){
                index++;

                if(index == s.length()){
                    flag = true;
                    break;
                }
            }

        }

        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
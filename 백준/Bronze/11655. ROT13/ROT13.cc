#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string s;
    getline(cin,s);

    for(char c: s){
        if(islower(c)){
            if( c+13 > 'z' )
                cout << char(c-13);
            else
                cout << char(c+13);
        }

        else if(isupper(c)){
            if(c+13 > 'Z')
                cout << char (c-13);
            else
                cout << char (c+13);
        }

        else
            cout << c;
    }

}
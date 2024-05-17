#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int count =0;

        string str;

        cin >> str;

        vector <char> fstr;

        for(int k=0; k<str.length(); k++){

            if(str[k] < 'a' || str[k] > 'z'){
                if(str[k]=='@'){
                    fstr.push_back('a');
                    count++;
                }
                else if(str[k]=='['){
                    fstr.push_back('c');
                    count++;
                }
                else if(str[k]=='!'){
                    fstr.push_back('i');
                    count++;
                }
                else if(str[k] ==';'){
                    fstr.push_back('j');
                    count++;
                }
                else if(str[k]=='^'){
                    fstr.push_back('n');
                    count++;
                }
                else if(str[k]=='0'){
                    fstr.push_back('o');
                    count++;
                }
                else if(str[k]=='7'){
                    fstr.push_back('t');
                    count++;
                }

                else if(str[k]=='\\' && str[k+1]=='\\'  && str[k+2] == '\''){
                    fstr.push_back('w');
                    count++;
                    k+=2;
                }

                else if(str[k]=='\\' && str[k+1] =='\''){
                    fstr.push_back('v');
                    count++;
                }


            }
            else{
                fstr.push_back(str[k]);
            }

        }

        if(count*2 >= fstr.size() ) {
            cout << "I don't understand" << endl;
        }

        else{
            for(char c : fstr){
                cout << c;
            }
            cout << endl;
        }

    }
}

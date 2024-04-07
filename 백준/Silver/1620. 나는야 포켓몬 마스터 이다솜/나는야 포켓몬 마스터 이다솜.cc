#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unordered_map <string,int> Pokemon;
    unordered_map <int,string> Numbers;

    int n,m;

    cin >> n >> m;

    string pokemon;

    for(int i=0;i<n;i++){
        cin >> pokemon;
        Pokemon.insert({pokemon,i+1});
        Numbers.insert({i+1,pokemon});
    }

    string x;

    for(int i=0;i<m;i++){
        cin >> x;

        if(isdigit(x[0])){

            auto it = Numbers.find(atoi(x.c_str()));

            cout << it-> second << "\n";

        }
        else{
            auto it = Pokemon.find(x);

            cout << it-> second << "\n";
        }
    }
}

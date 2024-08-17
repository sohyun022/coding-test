#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int total=0;

    string integer={};

    for(char C : s){
        if(C==','){
            total+=stoi(integer);
            integer={};
        }
        else
            integer+=C;
    }

    total+=stoi(integer);

    cout << total;
    
}

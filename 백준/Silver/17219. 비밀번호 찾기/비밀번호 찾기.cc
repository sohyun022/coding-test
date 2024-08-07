#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    string domain;
    string password;
    unordered_map <string,string> map;

    for(int i=0;i<n;i++){
        cin >> domain >> password;
        map[domain] = password;
    }

    string find_pw;

    for(int i=0;i<m;i++){
        cin >> find_pw;
        cout << map[find_pw] <<"\n";
    }

}
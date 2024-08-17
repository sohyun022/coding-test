#include <iostream>
#include <cstring>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char s[101]="";
    cin >> s;

    int total=0;

    char * token = strtok(s,",");

    while(token != NULL){
        total += stoi(token);
        token = strtok(NULL,",");
    }

    cout << total;

}
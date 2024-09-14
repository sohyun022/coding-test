#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int,int> map;

    int assignment;

    for(int i=0;i<28;i++){
        cin >> assignment;
        map[assignment]=1;
    }

    for(int i=1;i<=30;i++){
        if(map[i]!=1)
            cout<< i <<"\n";
    }

}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;

vector<int> coor;
vector<int> copied;
unordered_map<int,int> map;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    coor.resize(n);
    copied.resize(n);

    for(int i=0;i<n;i++){
        cin >> coor[i];
        copied[i]=coor[i];
    }

    sort(copied.begin(),copied.end());

    int count=0;

    map[copied[0]]=count++;

    for(int i=1;i<n;i++){
        if(copied[i] == copied[i-1]) continue;
        map[copied[i]]=count++;
    }

    for(int c : coor){
        cout << map[c] << " ";
    }

}

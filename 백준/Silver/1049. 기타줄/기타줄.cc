#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> bp(m);

    int minSet=1000;
    int minOne=1000;

    for(int i=0;i<m;i++){
        cin >> bp[i].first >> bp[i].second;
        if(bp[i].first < minSet) minSet = bp[i].first;
        if(bp[i].second < minOne) minOne = bp[i].second;
    }

    int totalCost=0;

    if(n>=6){
       if(minSet < minOne*6)
           totalCost += n/6*minSet;

       else
           totalCost += minOne*(n-n%6);

       n%=6;
    }

    if(n){
        if(minSet < minOne*n)
            totalCost += minSet;
        else
            totalCost += minOne*n;
    }

    cout << totalCost;

    return 0;
}

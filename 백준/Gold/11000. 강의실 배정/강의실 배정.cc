#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(),v.end());

    priority_queue<int,vector<int>,greater<>> pq;
    
    pq.push(v[0].second);

    for(int i=1;i<n;i++){
        if(pq.top() <= v[i].first){
            pq.pop();
            pq.push(v[i].second);
        }

        else{
            pq.push(v[i].second);
        }
    }

    cout << pq.size();

}
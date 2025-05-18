#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r=0;
int n;
int farNode=0;
vector<pair<int,int>> adj[10001];
vector<int> visited(10001,false);

void dfs(int node, int dist){

    visited[node]=true;

    if(dist > r){
        r = dist;
        farNode = node;
    }

    for(auto a : adj[node]){
        if(!visited[a.first]){

            dfs(a.first, dist+a.second);
        }
    }
}

int main() {

    cin >> n;
    int p,c,w;

    for(int i=0;i<n-1;i++){
        cin >> p >> c >> w;
        adj[p].emplace_back(c,w);
        adj[c].emplace_back(p,w);
    }

    dfs(1, 0);

    visited.assign(10001,0);
    r=0;

    dfs(farNode,0);

    cout << r;
}

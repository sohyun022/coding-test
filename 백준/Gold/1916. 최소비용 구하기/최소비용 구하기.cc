#include <iostream>
#include <queue>
#include<vector>
#include <climits>
using namespace std;

int INF=INT_MAX;

int n,m;
int a,b;

vector<pair<int,int>> adj[100001];

void addEdge(int u,int v,int w){
    adj[u].emplace_back(v,w);
}

void dijkstra(){
    vector<int> dist(n+1,INF);
    dist[a]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.emplace(0,a);

    while(!pq.empty()){
        int u=pq.top().second;
        int curD=pq.top().first;
        pq.pop();

        if(curD>dist[u]) continue;

        for(const auto& [v,w] :adj[u]){
            if(dist[u] != INF && dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                pq.emplace(dist[v],v);
            }
        }
    }

    cout << dist[b];
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        addEdge(u,v,w);
    }

    cin >> a >> b;

    dijkstra();

}
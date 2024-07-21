#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> adj[20001];

void addEdge( int u, int v, int weight) {
    adj[u].emplace_back(v, weight);
}

void dijkstra(int V, int src) {

    vector<int> dist(V+1, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& [v, weight] : adj[u]) {

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }

        }
    }


    for (int i = 1; i <= V; i++) {

        if(dist[i] == INF){
            cout << "INF" << "\n";
        }
        else
            cout  << dist[i] << "\n";

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V,E,src;

    cin >> V >> E >> src;

    for(int i=0;i<E;i++){
        int u,v,w;

        cin >> u >> v >> w;

        addEdge(u,v,w);
    }

    dijkstra(V,src);

}
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // {weight, node}

vector<int> dijkstra(int startNode, int numNodes, const vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(numNodes, INT_MAX);
    
    dist[startNode] = 0;
    pq.push({0, startNode});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.second;
            int weight = edge.first;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int numNodes = 5;
    vector<vector<pii>> adj(numNodes);
    adj[0].push_back({4, 1});
    adj[0].push_back({1, 2});
    adj[2].push_back({2, 1});
    adj[1].push_back({1, 3});
    adj[2].push_back({5, 3});
    
    vector<int> dist = dijkstra(0, numNodes, adj);
    
    cout << "Shortest distances from 0: ";
    for (int d : dist) cout << d << " ";
    cout << endl;
    
    return 0;
}

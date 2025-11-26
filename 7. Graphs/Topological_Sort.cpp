#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Topological Sort using DFS
void topoSortUtil(int u, vector<bool>& visited, stack<int>& s, const vector<vector<int>>& adj) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            topoSortUtil(v, visited, s, adj);
        }
    }
    s.push(u);
}

void topologicalSortDFS(int numNodes, const vector<vector<int>>& adj) {
    stack<int> s;
    vector<bool> visited(numNodes, false);
    
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            topoSortUtil(i, visited, s, adj);
        }
    }
    
    cout << "Topo Sort (DFS): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Kahn's Algorithm (BFS)
void topologicalSortBFS(int numNodes, const vector<vector<int>>& adj) {
    vector<int> inDegree(numNodes, 0);
    for (int u = 0; u < numNodes; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < numNodes; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    cout << "Topo Sort (BFS): ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }
    cout << endl;
}

int main() {
    int numNodes = 6;
    vector<vector<int>> adj(numNodes);
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    
    topologicalSortDFS(numNodes, adj);
    topologicalSortBFS(numNodes, adj);
    
    return 0;
}

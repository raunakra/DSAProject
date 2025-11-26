#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Graph represented as Adjacency List
void bfs(int startNode, int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(numNodes, false);
    queue<int> q;
    
    visited[startNode] = true;
    q.push(startNode);
    
    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int u, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, visited, adj);
        }
    }
}

void dfs(int startNode, int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(numNodes, false);
    cout << "DFS: ";
    dfsUtil(startNode, visited, adj);
    cout << endl;
}

int main() {
    int numNodes = 5;
    vector<vector<int>> adj(numNodes);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    
    bfs(0, numNodes, adj);
    dfs(0, numNodes, adj);
    
    return 0;
}

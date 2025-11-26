#include <iostream>
#include <vector>

using namespace std;

// Detect Cycle in Directed Graph (DFS)
bool isCyclicUtil(int u, vector<bool>& visited, vector<bool>& recStack, const vector<vector<int>>& adj) {
    if (!visited[u]) {
        visited[u] = true;
        recStack[u] = true;
        
        for (int v : adj[u]) {
            if (!visited[v] && isCyclicUtil(v, visited, recStack, adj))
                return true;
            else if (recStack[v])
                return true;
        }
    }
    recStack[u] = false;
    return false;
}

bool isCyclicDirected(int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(numNodes, false);
    vector<bool> recStack(numNodes, false);
    
    for (int i = 0; i < numNodes; i++) {
        if (isCyclicUtil(i, visited, recStack, adj))
            return true;
    }
    return false;
}

// Detect Cycle in Undirected Graph (DFS)
bool isCyclicUndirectedUtil(int u, int parent, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (isCyclicUndirectedUtil(v, u, visited, adj))
                return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool isCyclicUndirected(int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(numNodes, false);
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (isCyclicUndirectedUtil(i, -1, visited, adj))
                return true;
        }
    }
    return false;
}

int main() {
    // Directed Graph with Cycle
    vector<vector<int>> adjDir(3);
    adjDir[0] = {1};
    adjDir[1] = {2};
    adjDir[2] = {0};
    cout << "Directed Cycle: " << isCyclicDirected(3, adjDir) << endl;
    
    return 0;
}

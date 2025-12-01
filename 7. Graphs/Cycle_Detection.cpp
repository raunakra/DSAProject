#include <iostream>
#include <vector>
#include <queue>

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

// Detect Cycle in Undirected Graph (BFS)
bool isCyclicUndirectedBFS(int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(numNodes, false);
    vector<int> parent(numNodes, -1);

    for (int s = 0; s < numNodes; ++s) {
        if (visited[s]) continue;
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v) {
                    // visited and not parent -> cycle
                    return true;
                }
            }
        }
    }
    return false;
}

// Detect Cycle in Directed Graph (BFS / Kahn's algorithm)
bool isCyclicDirectedBFS(int numNodes, const vector<vector<int>>& adj) {
    vector<int> indeg(numNodes, 0);
    for (int u = 0; u < numNodes; ++u) {
        for (int v : adj[u]) indeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < numNodes; ++i) if (indeg[i] == 0) q.push(i);

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ++cnt;
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    // if count of visited nodes in topological sort != numNodes => cycle
    return cnt != numNodes;
}

int main() {
    // Directed Graph with Cycle
    vector<vector<int>> adjDir(3);
    adjDir[0] = {1};
    adjDir[1] = {2};
    adjDir[2] = {0};
    cout << "Directed Cycle (DFS): " << isCyclicDirected(3, adjDir) << endl;
    cout << "Directed Cycle (BFS/Kahn): " << isCyclicDirectedBFS(3, adjDir) << endl;

    // Undirected Graph with Cycle
    // 0--1
    // |  |
    // 3--2
    vector<vector<int>> adjUndir(4);
    adjUndir[0] = {1,3};
    adjUndir[1] = {0,2};
    adjUndir[2] = {1,3};
    adjUndir[3] = {0,2};

    cout << "Undirected Cycle (DFS): " << isCyclicUndirected(4, adjUndir) << endl;
    cout << "Undirected Cycle (BFS): " << isCyclicUndirectedBFS(4, adjUndir) << endl;
    
    return 0;
}

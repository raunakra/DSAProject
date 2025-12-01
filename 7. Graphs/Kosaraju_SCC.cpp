#include <bits/stdc++.h>
using namespace std;

// Kosaraju's algorithm to find strongly connected components (SCCs)
// Time: O(V + E) — two DFS passes plus building reverse graph
// Space: O(V + E) — reverse adjacency list + recursion/visited arrays
// Notes: Uses two DFS passes: the first builds finish order, the second
// extracts components on the reversed graph. Works for directed graphs.

void dfs1(int u, vector<bool> &vis, const vector<vector<int>> &adj, vector<int> &order) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfs1(v, vis, adj, order);
    order.push_back(u);
}

void dfs2(int u, vector<bool> &vis, const vector<vector<int>> &radj, vector<int> &component) {
    vis[u] = true;
    component.push_back(u);
    for (int v : radj[u]) if (!vis[v]) dfs2(v, vis, radj, component);
}

vector<vector<int>> kosarajuSCC(int n, const vector<vector<int>> &adj) {
    vector<bool> vis(n, false);
    vector<int> order;
    order.reserve(n);

    for (int i = 0; i < n; ++i) if (!vis[i]) dfs1(i, vis, adj, order);

    // build reverse graph
    vector<vector<int>> radj(n);
    for (int u = 0; u < n; ++u) for (int v : adj[u]) radj[v].push_back(u);

    fill(vis.begin(), vis.end(), false);
    vector<vector<int>> sccs;

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (!vis[u]) {
            vector<int> comp;
            dfs2(u, vis, radj, comp);
            sccs.push_back(comp);
        }
    }

    return sccs;
}

// Small pretty-printer for SCCs
void printSCCs(const vector<vector<int>> &sccs) {
    cout << "Found " << sccs.size() << " SCC(s):\n";
    for (size_t i = 0; i < sccs.size(); ++i) {
        cout << "SCC " << i+1 << ": ";
        for (int v : sccs[i]) cout << v << ' ';
        cout << '\n';
    }
}

int main() {
    // Example 1: Graph with 5 nodes and SCCs
    // 0 -> 2 -> 1 -> 0 (cycle), 3 -> 4
    int n1 = 5;
    vector<vector<int>> adj1(n1);
    adj1[0] = {2};
    adj1[1] = {0};
    adj1[2] = {1};
    adj1[3] = {4};
    adj1[4] = {};

    cout << "Example Graph 1:\n";
    auto sccs1 = kosarajuSCC(n1, adj1);
    printSCCs(sccs1);

    // Example 2: Larger graph with multiple SCCs
    int n2 = 8;
    vector<vector<int>> adj2(n2);
    adj2[0] = {1};
    adj2[1] = {2,4};
    adj2[2] = {0,3};
    adj2[3] = {2,5};
    adj2[4] = {5};
    adj2[5] = {6};
    adj2[6] = {4,7};
    adj2[7] = {6};

    cout << "\nExample Graph 2:\n";
    auto sccs2 = kosarajuSCC(n2, adj2);
    printSCCs(sccs2);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Amount of Time for Binary Tree to Be Infected
// Problem: Given a binary tree and a start node, an infection spreads from the start node.
// In one unit of time, the infection spreads to all adjacent nodes (parent, left child, right child).
// Return the amount of time needed for the entire tree to be infected.
//
// Example:
//   Input: root = [1,5,3,null,4,10,6,9,2], start = 3
//          Tree:      1
//                   /   \
//                  5     3
//                   \   / \
//                    4 10  6
//                   / \
//                  9   2
//   Output: 4
//   Explanation: 
//     Minute 0: Node 3 is infected
//     Minute 1: Nodes 1, 10, 6 are infected
//     Minute 2: Nodes 5 are infected
//     Minute 3: Node 4 is infected
//     Minute 4: Nodes 9, 2 are infected
//
// Approach: 
//   1. Build parent pointers for all nodes (or use a parent map)
//   2. Perform BFS from the start node treating the tree as an undirected graph
//   3. Track visited nodes and count the levels of BFS
//
// Time Complexity: O(N) where N is the number of nodes (traverse once to build parent map, once for BFS)
// Space Complexity: O(N) for parent map, visited set, and BFS queue

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void constructAdjacency(TreeNode* root, unordered_map<int, vector<int>> &adj)
{
    if(!root) return;

    if(root->left) 
    {
        adj[root->val].push_back(root->left-> val);
        adj[root->left->val].push_back(root->val);
    }

    if(root->right)
    {
        adj[root->val].push_back(root->right-> val);
        adj[root->right->val].push_back(root-> val);
    } 


    constructAdjacency(root->left,adj);

    constructAdjacency(root->right,adj);

}

int amountOfTime(TreeNode* root, int start) {
    unordered_map<int, vector<int>> adj;
    constructAdjacency(root, adj);

    queue<int> q;
    q.push(start);
    int time = -1;
    unordered_set<int> vis;

    while(!q.empty())
    {
        time++;
        int sz = q.size(); //adj nodes
        while(sz--)
        {
            auto fr = q.front(); q.pop();
            vis.insert(fr);

            for(auto x : adj[fr])
            {
                if(!vis.count(x))
                {
                    q.push(x);
                }
            }
        }
    }

    return time;
}

int main() {
    // Example 1: Tree from problem description
    //      1
    //    /   \
    //   5     3
    //    \   / \
    //     4 10  6
    //    / \
    //   9   2
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);
    
    cout << "Example 1 - Time to burn tree starting from node 3: " 
         << amountOfTime(root, 3) << " minutes\n"; // Expected: 4
    
    // Example 2: Simple tree
    //     1
    //    /
    //   2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    
    cout << "Example 2 - Time to burn tree starting from node 2: " 
         << amountOfTime(root2, 2) << " minutes\n"; // Expected: 1
    
    // Example 3: Start from root
    cout << "Example 3 - Time to burn tree starting from node 1: " 
         << amountOfTime(root, 1) << " minutes\n"; // Expected: 3
    
    return 0;
}

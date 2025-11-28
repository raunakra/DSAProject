#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Simple TreeNode used across examples in this repo
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Vertical order traversal: group nodes by horizontal distance (hd)
// We do a BFS (level order) and record the column (hd) for every node.
// This preserves top-to-bottom order within a column and naturally keeps
// left-to-right order for nodes at the same level.
vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    map<int, vector<int>> cols;              // hd -> list of node values
    queue<pair<TreeNode*, int>> q;           // node + hd
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        cols[hd].push_back(node->val);
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto &p : cols) res.push_back(p.second);
    return res;
}

// Helper to print the vertical order (each inner vector as a column)
void printVertical(const vector<vector<int>>& cols) {
    cout << "Vertical order (columns left->right):\n";
    for (const auto &col : cols) {
        cout << "[ ";
        for (int x : col) cout << x << " ";
        cout << "]\n";
    }
}

int main() {
    // Sample tree
    //              1
    //           /     \
    //          2       3
    //         / \     / \
    //        4   5   6   7
    //             \     /
    //              8   9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    auto cols = verticalOrder(root);
    printVertical(cols);

    // Expected columns (left -> right):
    // [4], [2], [1,5,6], [3,8,9], [7]

    return 0;
}

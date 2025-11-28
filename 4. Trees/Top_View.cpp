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

// Top view: first node encountered at each horizontal distance (hd) in BFS
vector<int> topView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    // map hd -> node value (first occurrence only)
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q; // node and horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        // if not seen a node at this hd yet, record it
        if (!mp.count(hd)) mp[hd] = node->val;
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto &p : mp) res.push_back(p.second);
    return res;
}

// Helper to print vector
void printVec(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    // Sample tree
    //              1
    //           /     \
    //          2       3
    //         / \     / \
    //        4   5   6   7
    //             \
    //              8
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    cout << "Top view: ";
    printVec(topView(root)); // expected order: 4 2 1 3 7

    return 0;
}

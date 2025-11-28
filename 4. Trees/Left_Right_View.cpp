#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Simple TreeNode used across examples in this repo
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Approach 1: Level-order (BFS) — capture first/last node at each level
vector<int> leftViewBFS(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) res.push_back(node->val); // first node at this level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}

vector<int> rightViewBFS(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            if (i == sz - 1) res.push_back(node->val); // last node at this level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}

// Approach 2: DFS recursion (track maximum level seen)
void leftViewDFSUtil(TreeNode* node, int level, int &maxLevel, vector<int>& out) {
    if (!node) return;
    if (level > maxLevel) {
        out.push_back(node->val);
        maxLevel = level;
    }
    // traverse left first for left view
    leftViewDFSUtil(node->left, level + 1, maxLevel, out);
    leftViewDFSUtil(node->right, level + 1, maxLevel, out);
}

vector<int> leftViewDFS(TreeNode* root) {
    vector<int> out; int maxLevel = 0; // use level starting at 1
    leftViewDFSUtil(root, 1, maxLevel, out);
    return out;
}

void rightViewDFSUtil(TreeNode* node, int level, int &maxLevel, vector<int>& out) {
    if (!node) return;
    if (level > maxLevel) {
        out.push_back(node->val);
        maxLevel = level;
    }
    // traverse right first for right view
    rightViewDFSUtil(node->right, level + 1, maxLevel, out);
    rightViewDFSUtil(node->left, level + 1, maxLevel, out);
}

vector<int> rightViewDFS(TreeNode* root) {
    vector<int> out; int maxLevel = 0;
    rightViewDFSUtil(root, 1, maxLevel, out);
    return out;
}

// Helper to print vectors
void printVec(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    // Build a sample tree
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

    cout << "Left / Right view examples (BFS):" << endl;
    cout << "Left view BFS: "; printVec(leftViewBFS(root)); // expected 1 2 4 8
    cout << "Right view BFS: "; printVec(rightViewBFS(root)); // expected 1 3 7 8

    cout << "Left / Right view examples (DFS):" << endl;
    cout << "Left view DFS: "; printVec(leftViewDFS(root));
    cout << "Right view DFS: "; printVec(rightViewDFS(root));

    return 0;
}

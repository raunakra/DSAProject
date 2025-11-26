#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1. Inorder Traversal (Recursive)
void inorderRecursive(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorderRecursive(root->left, res);
    res.push_back(root->val);
    inorderRecursive(root->right, res);
}

// 2. Preorder Traversal (Iterative)
vector<int> preorderIterative(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        res.push_back(node->val);
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    return res;
}

// 3. Postorder Traversal (Iterative - 2 stacks or reverse preorder)
vector<int> postorderIterative(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        res.push_back(s2.top()->val);
        s2.pop();
    }
    return res;
}

// 4. Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    vector<int> res;
    inorderRecursive(root, res);
    cout << "Inorder: ";
    for(int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}

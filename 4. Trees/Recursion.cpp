#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Maximum Depth of Binary Tree
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Symmetric Tree
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) && 
           isMirror(t1->right, t2->left) && 
           isMirror(t1->left, t2->right);
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

// Invert Binary Tree
TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    cout << "Max Depth: " << maxDepth(root) << endl;
    return 0;
}

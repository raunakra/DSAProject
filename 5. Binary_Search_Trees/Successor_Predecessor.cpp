#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Successor
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL;
    while (root) {
        if (p->val < root->val) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// Inorder Predecessor
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* predecessor = NULL;
    while (root) {
        if (p->val > root->val) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    TreeNode* p = root->left; // Node 3
    
    TreeNode* succ = inorderSuccessor(root, p);
    if (succ) cout << "Successor of 3: " << succ->val << endl;
    
    return 0;
}

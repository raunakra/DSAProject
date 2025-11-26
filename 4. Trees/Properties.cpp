#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1. Diameter of Binary Tree
int diameter = 0;
int depth(TreeNode* root) {
    if (!root) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    diameter = max(diameter, leftDepth + rightDepth);
    return 1 + max(leftDepth, rightDepth);
}
int diameterOfBinaryTree(TreeNode* root) {
    diameter = 0;
    depth(root);
    return diameter;
}

// 2. Lowest Common Ancestor (LCA)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

// 3. Balanced Binary Tree
bool isBalanced(TreeNode* root) {
    if (!root) return true;
    int leftH = depth(root->left); // Reusing depth function (without diameter logic ideally)
    int rightH = depth(root->right);
    return abs(leftH - rightH) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;
    return 0;
}

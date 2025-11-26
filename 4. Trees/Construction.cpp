#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Construct Binary Tree from Preorder and Inorder Traversal
unordered_map<int, int> inorderMap;
int preorderIndex;

TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
    if (left > right) return NULL;
    
    int rootValue = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootValue);
    
    root->left = arrayToTree(preorder, left, inorderMap[rootValue] - 1);
    root->right = arrayToTree(preorder, inorderMap[rootValue] + 1, right);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    preorderIndex = 0;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    return arrayToTree(preorder, 0, preorder.size() - 1);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    
    TreeNode* root = buildTree(preorder, inorder);
    
    cout << "Reconstructed Inorder: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Flatten BST to Sorted List/Array (Inorder Traversal)
void bstToSortedArray(TreeNode* root, vector<int>& res) {
    if (!root) return;
    bstToSortedArray(root->left, res);
    res.push_back(root->val);
    bstToSortedArray(root->right, res);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    
    vector<int> sortedArr;
    bstToSortedArray(root, sortedArr);
    
    cout << "Sorted Array: ";
    for(int x : sortedArr) cout << x << " ";
    cout << endl;
    
    return 0;
}

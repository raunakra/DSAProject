#include <iostream>
#include <vector>

using namespace std;

// Morris Inorder Traversal (threaded traversal) - O(1) extra space
// Returns the inorder traversal sequence for the tree represented by arrays
// Here we construct a small binary tree via a simple TreeNode struct.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

vector<int> morrisInorder(TreeNode* root) {
    vector<int> res;
    TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            // find predecessor
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;

            if (!pred->right) {
                // create temporary thread to current
                pred->right = cur;
                cur = cur->left;
            } else {
                // thread exists -> visit current and remove thread
                pred->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return res;
}

// recursive inorder for comparison
void inorderRec(TreeNode* root, vector<int>& out) {
    if (!root) return;
    inorderRec(root->left, out);
    out.push_back(root->val);
    inorderRec(root->right, out);
}

int main() {
    // Build a small tree
    //         1
    //        / \
    //       2   3
    //      / \   
    //     4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> m = morrisInorder(root);
    vector<int> r;
    inorderRec(root, r);

    cout << "Morris Inorder: ";
    for (int x : m) cout << x << " ";
    cout << endl;

    cout << "Recursive Inorder: ";
    for (int x : r) cout << x << " ";
    cout << endl;

    // expected: 4 2 5 1 3
    return 0;
}

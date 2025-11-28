#include <bits/stdc++.h>
using namespace std;

// Check if a binary tree satisfies the children sum property:
// For every non-leaf node, node->val == (sum of left child val + right child val)

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// Returns true if tree rooted at `root` satisfies children sum property
bool childrenSumProperty(Node* root) {
    if (!root) return true;                 // empty tree trivially satisfies
    if (!root->left && !root->right) return true; // leaf node

    int l = 0, r = 0;
    if (root->left) l = root->left->val;
    if (root->right) r = root->right->val;

    if (root->val != l + r) return false;

    // recursively check left and right subtrees
    return childrenSumProperty(root->left) && childrenSumProperty(root->right);
}

// Helper to create a small demo tree and run checks
int main() {
    // Example 1: satisfies children sum property
    //        10
    //       /  \
    //      8    2
    //     / \    \
    //    3   5    2
    Node* root1 = new Node(10);
    root1->left = new Node(8);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(5);
    root1->right->right = new Node(2);

    cout << "Tree 1 satisfies children sum property? "
         << (childrenSumProperty(root1) ? "YES" : "NO") << "\n";

    // Example 2: does NOT satisfy
    //       10
    //      /  \
    //     5    3
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(3);

    cout << "Tree 2 satisfies children sum property? "
         << (childrenSumProperty(root2) ? "YES" : "NO") << "\n";

    // Cleanup (small; we're about to exit)
    // Note: deliberately not deleting every node here — short-lived demo.
    return 0;
}

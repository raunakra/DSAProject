// Boundary_Traversal.cpp
// Print the boundary traversal of a binary tree (anti-clockwise):
// left boundary (without leaves) -> leaves (left to right) -> right boundary (without leaves, bottom-up)
// Self-contained example with a small tree and sample output.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* node) {
    return node && !node->left && !node->right;
}

// Add left boundary excluding leaves
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->val);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

// Add leaves in left-to-right order
void addLeaves(Node* root, vector<int>& res) {
    if (!root) return;
    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

// Add right boundary excluding leaves (in reverse order)
void addRightBoundary(Node* root, vector<int>& res) {
    Node* cur = root->right;
    vector<int> temp;
    while (cur) {
        if (!isLeaf(cur)) temp.push_back(cur->val);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    // append in reverse to get bottom-up
    for (int i = (int)temp.size()-1; i >= 0; --i) res.push_back(temp[i]);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->val);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

int main() {
    // Construct sample tree:
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    //        / \    /
    //       8   9  10
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(10);

    vector<int> boundary = boundaryTraversal(root);
    cout << "Boundary traversal (anti-clockwise):\n";
    for (size_t i = 0; i < boundary.size(); ++i) {
        cout << boundary[i] << (i+1<boundary.size()? ' ':'\n');
    }

    // Clean up small tree to avoid leaks (not necessary for demo, but tidy)
    // In a real example use smart pointers or a tree destructor.
    delete root->left->left;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

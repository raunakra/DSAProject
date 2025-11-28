#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Computes maximum width of a binary tree.
// Width is measured as the number of positions between the leftmost and
// rightmost non-null nodes on the same level inclusive. To handle gaps
// we assign position indices to nodes (like a heap indexing scheme) and
// compute width = last_index - first_index + 1 on each level.
int maximumWidth(TreeNode* root) {
    if (!root) return 0;

    // pair of node + index (use unsigned long long to reduce overflow risk)
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    unsigned long long maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        unsigned long long leftIndex = q.front().second;
        unsigned long long rightIndex = leftIndex; // will update

        for (int i = 0; i < levelSize; ++i) {
            auto [node, idx] = q.front(); q.pop();
            // normalize indices by subtracting leftIndex to avoid very large numbers
            unsigned long long normalized = idx - leftIndex;
            rightIndex = idx;

            if (node->left) q.push({node->left, normalized * 2 + 1 + leftIndex});
            if (node->right) q.push({node->right, normalized * 2 + 2 + leftIndex});
        }

        unsigned long long width = rightIndex - leftIndex + 1;
        if (width > maxWidth) maxWidth = width;
    }

    return static_cast<int>(maxWidth);
}

int main() {
    // Example tree:
    //          1
    //         / \
    //        2   3
    //       /     \
    //      4       5
    //       \     /
    //        6   7
    // Level widths (positions):
    // level 0: [1] => width 1
    // level 1: [2,3] => width 2
    // level 2: [4,.,.,5] => width 4 (since there is a gap)
    // level 3: [.,6,7,.] => width 4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);

    cout << "Maximum width: " << maximumWidth(root) << endl; // expected 4

    return 0;
}

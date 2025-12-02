#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming on Trees
// Problem: This file demonstrates common DP on tree patterns where we compute answers
// by combining results from subtrees. Common examples include:
// 1. Maximum path sum in a tree
// 2. House robber on a tree (max sum non-adjacent nodes)
// 3. Tree diameter (longest path between any two nodes)
//
// Approach: Use post-order DFS traversal where we:
//   - Recursively solve for all children
//   - Combine child results to compute answer for current node
//   - Update global answer if needed
//   - Return value(s) that parent needs
//
// Time Complexity: O(N) where N is the number of nodes (visit each node once)
// Space Complexity: O(H) where H is the height (recursion stack), O(N) worst case for skewed tree

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Pattern 1: Maximum Path Sum
// Find the maximum path sum where path is any sequence of nodes from some starting
// node to any ending node (path doesn't have to go through root)
class MaxPathSum {
private:
    int maxSum;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        // Get max path sum from left and right subtrees
        // Use max(0, ...) to ignore negative paths
        int leftMax = max(0, dfs(node->left));
        int rightMax = max(0, dfs(node->right));
        
        // Update global max considering path through current node
        maxSum = max(maxSum, node->val + leftMax + rightMax);
        
        // Return max path sum going through this node (can only pick one direction)
        return node->val + max(leftMax, rightMax);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};

// Pattern 2: House Robber III (Max sum with no two adjacent nodes)
// Given a binary tree where each node contains a value, find maximum sum
// such that no two selected nodes are directly connected (parent-child).
class HouseRobberIII {
private:
    // Returns {maxWithoutNode, maxWithNode}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto [leftNo, leftYes] = dfs(node->left);
        auto [rightNo, rightYes] = dfs(node->right);
        
        // If we don't take current node, we can take or not take children
        int withoutCurr = max(leftNo, leftYes) + max(rightNo, rightYes);
        
        // If we take current node, we cannot take children
        int withCurr = node->val + leftNo + rightNo;
        
        return {withoutCurr, withCurr};
    }
    
public:
    int rob(TreeNode* root) {
        auto [withoutRoot, withRoot] = dfs(root);
        return max(withoutRoot, withRoot);
    }
};

// Pattern 3: Tree Diameter (Longest path between any two nodes)
// Note: This is similar to max path sum but counts edges instead of node values
class TreeDiameter {
private:
    int diameter;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);
        
        // Update diameter considering path through current node
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return height of subtree rooted at this node
        return 1 + max(leftHeight, rightHeight);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }
};

// Pattern 4: Count nodes in subtree with specific property
// Example: Count nodes in subtree where sum equals a target
class SubtreeSum {
private:
    int count;
    int target;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        int totalSum = node->val + leftSum + rightSum;
        
        if (totalSum == target) count++;
        
        return totalSum;
    }
    
public:
    int countSubtreesWithSum(TreeNode* root, int targetSum) {
        count = 0;
        target = targetSum;
        dfs(root);
        return count;
    }
};

int main() {
    // Example tree:
    //       -10
    //       /  \
    //      9   20
    //         /  \
    //        15   7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    MaxPathSum mps;
    cout << "Maximum Path Sum: " << mps.maxPathSum(root) << '\n'; // Expected: 42 (15->20->7)
    
    HouseRobberIII hr;
    cout << "House Robber III (max sum non-adjacent): " << hr.rob(root) << '\n'; // Expected: 19 (9 + -10 or 20)
    
    TreeDiameter td;
    cout << "Tree Diameter (edges): " << td.diameterOfBinaryTree(root) << '\n'; // Expected: 3
    
    // Example 2: Simple tree for subtree sum
    //     1
    //    / \
    //   2   3
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    
    SubtreeSum ss;
    cout << "Count subtrees with sum 3: " << ss.countSubtreesWithSum(root2, 3) << '\n'; // Expected: 2 (node 3, and subtree 1-2)
    
    return 0;
}

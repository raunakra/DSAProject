#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Tree Questions

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Binary Tree Level Order Traversal (Amazon, Salesforce - Very Frequent)
// Time: O(n), Space: O(n)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    
    return result;
}

// 2. Maximum Depth of Binary Tree (Amazon, Salesforce - Very Frequent)
// Time: O(n), Space: O(h)
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// 3. Validate Binary Search Tree (Amazon - Very Frequent)
// Time: O(n), Space: O(h)
bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) && 
           isValidBST(root->right, root->val, maxVal);
}

// 4. Lowest Common Ancestor (Amazon, Salesforce - Very Frequent)
// Time: O(n), Space: O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}

// 5. Binary Tree Right Side View (Amazon - Frequent)
// Time: O(n), Space: O(n)
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (i == size - 1) result.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return result;
}

// 6. Serialize and Deserialize Binary Tree (Amazon - Very Frequent)
// Time: O(n), Space: O(n)
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        return to_string(root->val) + "," + 
               serialize(root->left) + 
               serialize(root->right);
    }
    
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string val;
        while (getline(ss, val, ',')) {
            nodes.push(val);
        }
        return buildTree(nodes);
    }
    
private:
    TreeNode* buildTree(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        
        if (val == "null") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(nodes);
        node->right = buildTree(nodes);
        return node;
    }
};

// 7. Kth Smallest Element in BST (Amazon - Frequent)
// Time: O(n), Space: O(h)
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node || count >= k) return;
        
        inorder(node->left);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorder(node->right);
    };
    
    inorder(root);
    return result;
}

// 8. Binary Tree Maximum Path Sum (Amazon - Very Frequent)
// Time: O(n), Space: O(h)
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        
        int leftMax = max(0, dfs(node->left));
        int rightMax = max(0, dfs(node->right));
        
        maxSum = max(maxSum, node->val + leftMax + rightMax);
        
        return node->val + max(leftMax, rightMax);
    };
    
    dfs(root);
    return maxSum;
}

// 9. Construct Binary Tree from Preorder and Inorder (Amazon - Frequent)
// Time: O(n), Space: O(n)
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    int preIdx = 0;
    function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
        if (left > right) return nullptr;
        
        int val = preorder[preIdx++];
        TreeNode* node = new TreeNode(val);
        
        int inIdx = inMap[val];
        node->left = build(left, inIdx - 1);
        node->right = build(inIdx + 1, right);
        
        return node;
    };
    
    return build(0, inorder.size() - 1);
}

// 10. Flatten Binary Tree to Linked List (Amazon - Frequent)
// Time: O(n), Space: O(h)
void flatten(TreeNode* root) {
    if (!root) return;
    
    flatten(root->left);
    flatten(root->right);
    
    TreeNode* right = root->right;
    root->right = root->left;
    root->left = nullptr;
    
    TreeNode* curr = root;
    while (curr->right) {
        curr = curr->right;
    }
    curr->right = right;
}

// 11. Invert Binary Tree (Amazon - Frequent)
// Time: O(n), Space: O(h)
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

// 12. Symmetric Tree (Salesforce - Frequent)
// Time: O(n), Space: O(h)
bool isSymmetric(TreeNode* root) {
    function<bool(TreeNode*, TreeNode*)> isMirror = [&](TreeNode* t1, TreeNode* t2) -> bool {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return t1->val == t2->val && 
               isMirror(t1->left, t2->right) && 
               isMirror(t1->right, t2->left);
    };
    
    return root ? isMirror(root->left, root->right) : true;
}

// Helper: Create binary tree from level order array
TreeNode* createTree(vector<int>& vals, int i = 0) {
    if (i >= vals.size() || vals[i] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(vals[i]);
    root->left = createTree(vals, 2*i + 1);
    root->right = createTree(vals, 2*i + 2);
    
    return root;
}

// Helper: Print level order
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << "\n";
}

int main() {
    // Create sample tree:       3
    //                          /   \
    //                         9    20
    //                             /  \
    //                            15   7
    vector<int> vals = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root = createTree(vals);
    
    cout << "Tree: ";
    printLevelOrder(root);
    
    // Level Order Traversal
    auto levels = levelOrder(root);
    cout << "\nLevel Order: ";
    for (auto& level : levels) {
        cout << "[";
        for (int v : level) cout << v << " ";
        cout << "] ";
    }
    cout << "\n";
    
    // Max Depth
    cout << "Max Depth: " << maxDepth(root) << "\n";
    
    // Validate BST
    cout << "Is Valid BST: " << (isValidBST(root) ? "true" : "false") << "\n";
    
    // Right Side View
    auto rightView = rightSideView(root);
    cout << "Right Side View: ";
    for (int v : rightView) cout << v << " ";
    cout << "\n";
    
    // Serialize and Deserialize
    Codec codec;
    string serialized = codec.serialize(root);
    cout << "\nSerialized: " << serialized << "\n";
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized: ";
    printLevelOrder(deserialized);
    
    // Max Path Sum
    cout << "\nMax Path Sum: " << maxPathSum(root) << "\n";
    
    // Invert Tree
    TreeNode* inverted = invertTree(root);
    cout << "Inverted Tree: ";
    printLevelOrder(inverted);
    
    return 0;
}

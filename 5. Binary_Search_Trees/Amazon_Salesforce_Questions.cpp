#include <bits/stdc++.h>
using namespace std;

// Amazon & Salesforce Frequently Asked Binary Search Tree Questions

// Binary Search Tree Node Definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Validate Binary Search Tree (Amazon, Salesforce - Very Frequent)
// Check if tree is a valid BST
// Time: O(n), Space: O(h)
bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (!root) return true;
    
    if (root->val <= minVal || root->val >= maxVal) return false;
    
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

// 2. Kth Smallest Element in BST (Amazon - Very Frequent)
// Find kth smallest element
// Time: O(h + k), Space: O(h)
int kthSmallest(TreeNode* root, int k) {
    int result = -1;
    int count = 0;
    
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

// 3. Lowest Common Ancestor of BST (Amazon, Salesforce - Frequent)
// Find LCA of two nodes in BST
// Time: O(h), Space: O(1) iterative
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return nullptr;
}

// 4. Convert Sorted Array to BST (Amazon, Salesforce - Very Frequent)
// Build height-balanced BST from sorted array
// Time: O(n), Space: O(log n)
TreeNode* sortedArrayToBST(vector<int>& nums) {
    function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = build(left, mid - 1);
        node->right = build(mid + 1, right);
        
        return node;
    };
    
    return build(0, nums.size() - 1);
}

// 5. BST Iterator (Amazon - Frequent)
// Implement in-order iterator for BST
// Time: O(1) average per call, Space: O(h)
class BSTIterator {
    stack<TreeNode*> st;
    
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

// 6. Delete Node in BST (Amazon - Frequent)
// Delete node and maintain BST property
// Time: O(h), Space: O(h)
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to delete found
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        // Node has two children: find inorder successor
        TreeNode* minNode = root->right;
        while (minNode->left) minNode = minNode->left;
        
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    }
    
    return root;
}

// 7. Insert into BST (Amazon - Frequent)
// Insert value into BST
// Time: O(h), Space: O(h) recursive
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}

// 8. Recover Binary Search Tree (Amazon - Frequent)
// Two nodes swapped, recover the BST
// Time: O(n), Space: O(1) with Morris traversal
void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;
        
        inorder(node->right);
    };
    
    inorder(root);
    
    if (first && second) {
        swap(first->val, second->val);
    }
}

// 9. Range Sum of BST (Amazon - Frequent)
// Sum of values in range [low, high]
// Time: O(n), Space: O(h)
int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    
    int sum = 0;
    
    if (root->val >= low && root->val <= high) {
        sum += root->val;
    }
    
    if (root->val > low) {
        sum += rangeSumBST(root->left, low, high);
    }
    
    if (root->val < high) {
        sum += rangeSumBST(root->right, low, high);
    }
    
    return sum;
}

// 10. Closest Binary Search Tree Value (Amazon - Frequent)
// Find value closest to target
// Time: O(h), Space: O(1)
int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    
    while (root) {
        if (abs(root->val - target) < abs(closest - target)) {
            closest = root->val;
        }
        
        root = (target < root->val) ? root->left : root->right;
    }
    
    return closest;
}

// 11. Two Sum IV - Input is BST (Amazon - Frequent)
// Find if there exist two elements that add up to k
// Time: O(n), Space: O(h)
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> seen;
    
    function<bool(TreeNode*)> search = [&](TreeNode* node) {
        if (!node) return false;
        
        if (seen.count(k - node->val)) return true;
        
        seen.insert(node->val);
        
        return search(node->left) || search(node->right);
    };
    
    return search(root);
}

// 12. Inorder Successor in BST (Amazon - Frequent)
// Find inorder successor of a node
// Time: O(h), Space: O(1)
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    
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

// 13. Convert BST to Greater Tree (Amazon - Frequent)
// Add sum of all greater values to each node
// Time: O(n), Space: O(h)
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    
    function<void(TreeNode*)> reverseInorder = [&](TreeNode* node) {
        if (!node) return;
        
        reverseInorder(node->right);
        
        sum += node->val;
        node->val = sum;
        
        reverseInorder(node->left);
    };
    
    reverseInorder(root);
    return root;
}

// Helper function to build tree from array (level-order, -1 for null)
TreeNode* buildTree(vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (!q.empty() && i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (i < values.size() && values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

int main() {
    // Build sample BST: 5,3,7,2,4,6,8
    vector<int> vals1 = {5,3,7,2,4,6,8};
    TreeNode* root1 = buildTree(vals1);
    
    // Validate BST
    cout << "Is Valid BST: " << (isValidBST(root1) ? "true" : "false") << "\n";
    
    // Kth Smallest Element
    cout << "3rd Smallest Element: " << kthSmallest(root1, 3) << "\n";
    
    // LCA
    TreeNode* p = root1->left;  // Node 3
    TreeNode* q = root1->right->left;  // Node 6
    TreeNode* lca = lowestCommonAncestor(root1, p, q);
    cout << "LCA of 3 and 6: " << lca->val << "\n";
    
    // Convert Sorted Array to BST
    vector<int> sortedArr = {1,2,3,4,5,6,7};
    TreeNode* bst = sortedArrayToBST(sortedArr);
    cout << "BST from sorted array created (root: " << bst->val << ")\n";
    
    // BST Iterator
    BSTIterator iterator(root1);
    cout << "BST Iterator: ";
    for (int i = 0; i < 3 && iterator.hasNext(); i++) {
        cout << iterator.next() << " ";
    }
    cout << "\n";
    
    // Insert into BST
    root1 = insertIntoBST(root1, 1);
    cout << "Inserted 1 into BST\n";
    
    // Range Sum
    cout << "Range Sum [3, 7]: " << rangeSumBST(root1, 3, 7) << "\n";
    
    // Closest Value
    cout << "Closest to 3.5: " << closestValue(root1, 3.5) << "\n";
    
    // Two Sum IV
    cout << "Two Sum (k=9): " << (findTarget(root1, 9) ? "true" : "false") << "\n";
    
    // Inorder Successor
    TreeNode* succ = inorderSuccessor(root1, root1->left);
    cout << "Inorder Successor of 3: " << (succ ? to_string(succ->val) : "null") << "\n";
    
    // Delete Node
    root1 = deleteNode(root1, 3);
    cout << "Deleted node 3 from BST\n";
    
    return 0;
}

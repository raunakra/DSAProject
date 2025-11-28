class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);

        return max(lh + rh, max(l,r));
    }
};
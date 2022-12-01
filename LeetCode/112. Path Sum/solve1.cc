class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (not root) return false;
        int cur = root->val;
        if (((not root->left) and (not root->right)) and sum == cur)
            return true;
        if (root->left and hasPathSum(root->left, sum-cur))
            return true;
        if (root->right and hasPathSum(root->right, sum-cur))
            return true;
        
        return false;
    }
};

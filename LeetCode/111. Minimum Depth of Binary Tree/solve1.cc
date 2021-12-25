class Solution {
    public:
        int minDepth(TreeNode* root) {
            if (not root) return 0;
            if (not root->left and not root->right) return 1;
            if (root->left and root->right)
                return 1 + std::min(minDepth(root->left), minDepth(root->right));
            if (root->left)
                return 1 + minDepth(root->left);
            return 1 + minDepth(root->right);
        }
};

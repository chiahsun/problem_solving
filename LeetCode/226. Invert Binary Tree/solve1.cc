class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            invertTree(root->left);
            invertTree(root->right);
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = tmp;
        }
        return root;
    }
};

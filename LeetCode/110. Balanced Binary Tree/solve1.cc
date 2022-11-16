class Solution {
public:
    int getHeight(TreeNode * cur, bool & fail) {
        if (not cur or fail) return 0;
        int h1 = (cur->left) ? (getHeight(cur->left, fail)) : 0;
        int h2 = (cur->right) ? (getHeight(cur->right, fail)) : 0;
        if (abs(h1 - h2) > 1) fail = true;
        return 1 + std::max(h1, h2);
    }
    bool isBalanced(TreeNode* root) {
        bool fail = false;
        getHeight(root, fail);
        return not fail;
    }
};

class Solution {
public:
    bool isSymmetricHelper(TreeNode* pL, TreeNode* pR) {
        if (not pL and not pR) return true;
        if ((not pL) or (not pR)) return false;
        return (pL->val == pR->val) and isSymmetricHelper(pL->left, pR->right) and isSymmetricHelper(pL->right, pR->left);
    }
    bool isSymmetric(TreeNode* root) {
        return (not root) or isSymmetricHelper(root->left, root->right);
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p or root == q) return root;
        int pd = p->val - root->val;
        int qd = q->val - root->val;
        if (pd > 0 and qd > 0) return lowestCommonAncestor(root->right, p, q);
        if (pd < 0 and qd < 0) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

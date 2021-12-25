class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((not p and q) or (not q and p))
            return false;
        if (not p and not q)
            return true;
        return (p->val == q->val) and (isSameTree(p->left, q->left)) and (isSameTree(p->right, q->right));
    }
};

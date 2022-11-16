class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p or root == q) return root;
        int pval = p->val;
        int qval = q->val;
        if (pval > qval) return lowestCommonAncestor(root, q, p);
        
        TreeNode* cur = root;
        do {
            if (cur->val > pval and cur->val > qval) cur = cur->left;
            else if (cur->val < pval and cur->val < qval) cur = cur->right;
            else break;
        } while(true);
      
        return cur;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        if (!t1 && !t2) return NULL;
        
        int v1 = (t1 == NULL) ? 0 : t1->val;
        int v2 = (t2 == NULL) ? 0 : t2->val;
        int sum = v1 + v2;
        TreeNode *p = new TreeNode(sum);
        
        p->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
        p->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);
        
        return p;
    }
};

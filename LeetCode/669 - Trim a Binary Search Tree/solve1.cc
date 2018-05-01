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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;
        if ((root->val < L) || (root->val > R)) {
            TreeNode *pl = trimBST(root->left, L, R);
            if (pl) return pl;
            TreeNode *pr = trimBST(root->right, L, R);
            return pr;
        }
        
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        
        return root;
    }
};

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
    bool findNode(TreeNode* root, int value, int oriValue) {
        if (!root) return false;
        if (root->val > value) return findNode(root->left, value, oriValue);
        if (root->val < value) return findNode(root->right, value, oriValue);
        
        return root->val != oriValue;
    }
    
    bool findTarget(TreeNode* root, int k) {
        return findTarget(root, root, k);
    }
    
    bool findTarget(TreeNode *root, TreeNode *p, int k) {
        if (!p || !root) return false;
        return findNode(root, k-p->val, p->val) || findTarget(root, p->left, k) || findTarget(root, p->right, k);
    }
};

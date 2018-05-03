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
    void traversal(TreeNode *root, int &last) {
        if (!root) return;
        if (root->right) traversal(root->right, last);
        last = (root->val += last);
        if (root->left) traversal(root->left, last);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int last = 0;
        traversal(root, last);
        return root;
    }
};

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
    void inorder_traversal(TreeNode* root, TreeNode* &prev, int & min) {
        if (!root) return;
        
        if (root->left) inorder_traversal(root->left, prev, min);
        if (prev) { min = std::min(min, root->val - prev->val); }
        prev = root;
        if (root->right) inorder_traversal(root->right, prev, min);    
    }
    
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        int min = std::numeric_limits<int>::max();
        
        inorder_traversal(root, prev, min);
        return min;
    }
};

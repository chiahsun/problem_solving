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
    int getMax(TreeNode *p) {
        // assume p != NULL
        while (p->right) { p = p->right; }  
        return p->val;
    }
    
    int getMin(TreeNode *p) {
        while (p->left) { p = p->left; }
        return p->val;
    }
    
    int minDiffInBST(TreeNode* root) {
        int min = std::numeric_limits<int>::max();
        
        if (root->right) min = std::min(min, std::abs(root->val - getMin(root->right)));
        if (root->left) min = std::min(min, std::abs(root->val - getMax(root->left)));
        
        if (root->right) min = std::min(min, minDiffInBST(root->right));
        if (root->left) min = std::min(min, minDiffInBST(root->left));
        
        return min;
    }
};

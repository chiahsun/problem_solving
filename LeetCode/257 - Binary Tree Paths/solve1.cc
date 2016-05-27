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
    void binaryTreePathsHelper(vector<string> & v, TreeNode* now, string prefix) {
        prefix = prefix + (prefix.empty() ? "" : "->") + std::to_string(now->val);
        if (not now->left and not now->right) 
            v.push_back(prefix);
        else {
            if (now->left) binaryTreePathsHelper(v, now->left, prefix);
            if (now->right) binaryTreePathsHelper(v, now->right, prefix);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if (not root) return v;
        
        std::string prefix;
        binaryTreePathsHelper(v, root, prefix);
        return v;
    }
};

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
    void iterate(TreeNode *root, int level, std::vector<double> & v, std::vector<int> & nnodes) {
        if (!root) return;
        if (level == v.size()) {
            v.push_back(root->val);
            nnodes.push_back(0);
        }
        else v[level] += root->val;
        ++nnodes[level];
        
        if (root->left) iterate(root->left, level+1, v, nnodes);
        if (root->right) iterate(root->right, level+1, v, nnodes);
    }
        
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ans;
        std::vector<int> nnodes;
        iterate(root, 0, ans, nnodes);
        for (int i = 0; i < ans.size(); ++i) ans[i] /= nnodes[i];
        
        return ans;
    }
};

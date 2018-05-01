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
    int iterate(TreeNode *root, std::unordered_map<int, int> & freq) {
        if (!root) return 0;
        
        int leftsum = 0, rightsum = 0;
        if (root->left) leftsum = iterate(root->left, freq);
        if (root->right) rightsum = iterate(root->right, freq);
        
        int sum = leftsum + rightsum + root->val;
        auto it = freq.find(sum);
        if (it == freq.end()) freq.insert(std::make_pair(sum, 1));
        else ++it->second;
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::unordered_map<int, int> freq;
        iterate(root, freq);
        
        std::vector<int> ans;
        int max = 0;
        for (const auto & pr : freq) {
            if (pr.second > max) {
                ans.clear();
                ans.push_back(pr.first);
                max = pr.second;
            } else if (pr.second == max) {
                ans.push_back(pr.first);
            }
        }
        
        return ans;
    }
};

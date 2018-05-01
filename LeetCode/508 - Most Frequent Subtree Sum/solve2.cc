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
    int iterate(TreeNode *root, std::unordered_map<int, int> & freq, int & max, std::vector<int> & ans) {
        if (!root) return 0;
        
        int leftsum = 0, rightsum = 0;
        if (root->left) leftsum = iterate(root->left, freq, max, ans);
        if (root->right) rightsum = iterate(root->right, freq, max, ans);
        
        int sum = leftsum + rightsum + root->val;
        auto it = freq.find(sum);
        int curFreq = 1;
        if (it == freq.end()) {
            freq.insert(std::make_pair(sum, curFreq));
        } else {
            curFreq = ++it->second;
        }
        if (curFreq >= max) {
            if (curFreq > max) {
                ans.clear();
                max = curFreq;
            }
            ans.push_back(sum);
        } 
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::unordered_map<int, int> freq;
        std::vector<int> ans;
        int max = 0;
        iterate(root, freq, max, ans);
        
        return ans;
    }
};

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return construct(nums, 0, nums.size());
    }
    
    TreeNode* construct(vector<int>& nums, int from, int to) {
        if (from >= to) {
            return NULL;
        }
        
        int maxpos = from, maxval = nums[from];
        for (int i = from+1; i < to; ++i) {
            if (nums[i] > maxval) {
                maxpos = i;
                maxval = nums[i];
            }
        }
        TreeNode *p = new TreeNode(maxval);
        p->left = construct(nums, from, maxpos);
        p->right = construct(nums, maxpos+1, to);
        
        return p;
    }
};

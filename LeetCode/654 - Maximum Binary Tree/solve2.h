struct pair_compare {
    bool operator() (const std::pair<int, int> & x, const std::pair<int, int> & y) {
        return x.first < y.first;
    }
} my_pair_compare;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        std::vector<std::pair<int, int> > v;
        for (int i = 0; i < nums.size(); ++i) {
            v.push_back(std::make_pair(nums[i], i));
        }
        std::sort(v.begin(), v.end(), my_pair_compare);
        return construct(v);
    }
    
    // value, position
    TreeNode* construct(vector<std::pair<int, int> > & ordered) {
        if (ordered.size() == 0)
            return NULL;
        
        std::pair<int, int> top = ordered.back();
        int top_pos = top.second;
        std::vector<std::pair<int, int> > left, right;
        for (int i = 0; i < ordered.size()-1; ++i) {
            std::pair<int, int> cur = ordered[i];
            if (cur.second < top_pos) left.push_back(cur);
            else                      right.push_back(cur);
        }
        
        TreeNode *p = new TreeNode(top.first);
        p->left = construct(left);
        p->right = construct(right);
        return p;
    }
};

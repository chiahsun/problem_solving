class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > vecLevel;
        std::queue<TreeNode*> q;
        if (root) q.push(root);
        
        while (not q.empty()) {
            std::queue<TreeNode*> qi;
            while (not q.empty()) {
                qi.push(q.front()); q.pop();
            }
            
            std::vector<int> level;
            while (not qi.empty()) {
                TreeNode* cur = qi.front(); qi.pop();
                level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            vecLevel.push_back(level);
        }
        
        return vecLevel;
    }
};

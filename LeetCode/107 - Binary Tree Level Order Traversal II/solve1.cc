class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int> > vecLevels;
        std::queue<TreeNode*> q;

        if (root)
            q.push(root);        
        while (not q.empty()) {
            std::vector<int> vec;
            std::queue<TreeNode*> qi;
            
            while (not q.empty()) {
                qi.push(q.front()); q.pop();
            }
             
            while (not qi.empty()) {
                TreeNode* f = qi.front(); qi.pop();
                vec.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            vecLevels.push_back(vec);
        }
        std::reverse(vecLevels.begin(), vecLevels.end());
        return vecLevels;
    }
};

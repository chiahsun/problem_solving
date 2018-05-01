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
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ans;
        
        std::queue<TreeNode*> q[2];
        int pos = 0;
        
        if (root) {
            q[pos].push(root);
        }
        
        while (!q[pos].empty()) {
            std::queue<TreeNode*>& qcur = q[pos];
            std::queue<TreeNode*>& qnext = q[1-pos];
            
            double sum = 0; 
            int nnode = 0; 
            while (!qcur.empty()) {
                TreeNode *top = qcur.front(); qcur.pop();
                sum += top->val;
                ++nnode;
                if (top->left) qnext.push(top->left);
                if (top->right) qnext.push(top->right);
            }
            ans.push_back(sum/nnode);
            
            pos = 1 - pos;
        }
        
        return ans;
    }
};

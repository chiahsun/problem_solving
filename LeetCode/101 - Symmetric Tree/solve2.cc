class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (not root) return true;
        std::queue<TreeNode*> qL, qR;
        qL.push(root->left);
        qR.push(root->right);
        
        while (not qL.empty()) {
            TreeNode* l = qL.front(); qL.pop();
            TreeNode* r = qR.front(); qR.pop();
            
            if ((not l and r) or (not r and l)) return false;
            if (l and r) {
                if (l->val != r->val) return false;
                qL.push(l->left); qL.push(l->right);
                qR.push(r->right); qR.push(r->left);
            }
        }
        return true;
    }
};

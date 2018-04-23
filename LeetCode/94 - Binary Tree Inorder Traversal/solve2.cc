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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> v;
        
        std::stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *top = st.top(); st.pop();
            if (top != NULL && (top->left || top->right)) {
                if (top->right != NULL) st.push(top->right);
                st.push(top);
                if (top->left != NULL) st.push(top->left);
                
                top->left = top->right = NULL;
            } else if (top != NULL) {
                v.push_back(top->val);
            }
        }
        
        return v;
    }
};

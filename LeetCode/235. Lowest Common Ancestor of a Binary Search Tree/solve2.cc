class Solution {
public:
    int ascend(int x) { 
        return (x % 2 == 0) ? (x - 2)/2 : (x - 1)/2;
    }
    
    void find_pq(TreeNode* cur, int cur_id, TreeNode* p, int & pid, TreeNode* q, int & qid) {
        if (pid and qid) return;
        
        if (cur->left) {
            if (not pid and cur->left == p) { pid = 2*cur_id + 1; }
            else if (not qid and cur->left == q) { qid = 2*cur_id +1; }
            find_pq(cur->left, 2*cur_id+1, p, pid, q, qid);
        }
        if (cur->right) {
            if (not pid and cur->right == p) { pid = 2*cur_id + 2; }
            else if (not qid and cur->right == q) { qid = 2*cur_id + 2; }
            find_pq(cur->right, 2*cur_id+2, p, pid, q, qid);
        }
    }
    
    TreeNode* seek(TreeNode* root, int id) {
        std::stack<bool> st;
        while (id != 0) {
            if (id % 2 == 0) { id = (id - 2)/2; st.push(true);  }
            else             { id = (id - 1)/2; st.push(false); }
        }
        TreeNode* cur = root;
        while (not st.empty()) {
            bool dir = st.top(); st.pop();
            if (not dir) cur = cur->left;
            else         cur = cur->right;
        }
        return cur;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (not p) return q;
        if (not q) return p;
        if (p == root or q == root) return root;
        if (p == q) return p;
        
        int pid = 0, qid = 0;
        find_pq(root, 0, p, pid, q, qid);
        while (pid != qid) {
            if (pid > qid) pid = ascend(pid);
            else           qid = ascend(qid);
        }
    
        return seek(root, pid);    
    }
};

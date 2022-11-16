class Solution {
public:
    map<std::pair<TreeNode*, TreeNode*>, bool> mapParentChild;
    
    bool hasChild(TreeNode* root, TreeNode* p) {
        if (not root)
            return false;
        if (not p)
            return true;
        std::pair<TreeNode*, TreeNode*> pr = std::make_pair(root, p);
        if (mapParentChild.count(pr))
            return mapParentChild[pr];   
        if (root == p or root->left == p or root->right == p) {
            mapParentChild.insert(std::make_pair(pr, true));
            return true;
        }
        bool res = (root->right and hasChild(root->right, p)) or (root->left and hasChild(root->left, p));
        mapParentChild.insert(std::make_pair(pr, res));
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (not root) return root;
        if (not p) return q;
        if (not q) return p;
        if (p == q) return p;
        if (root == p or root == q) return root;

        if (root->left and hasChild(root->left, p) and hasChild(root->left, q))
            return lowestCommonAncestor(root->left, p, q);
        if (root->right and hasChild(root->right, p) and hasChild(root->right, q))
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

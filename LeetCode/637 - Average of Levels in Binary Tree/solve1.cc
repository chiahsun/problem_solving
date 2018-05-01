#include <iostream>
#include <vector>
#include <queue>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include "solve1.h"

TreeNode* buildTree() {
    
    int x;

    std::queue<TreeNode*> q;
    std::cin >> x;
    TreeNode *root = nullptr;
    if (x != -1) {
        root = new TreeNode(x);
        q.push(root);
    }
    while (!q.empty()) {
        TreeNode *top = q.front(); q.pop();
        std::cin >> x;
        if (x != -1) {
            top->left = new TreeNode(x);
            q.push(top->left);
        }
        std::cin >> x;
        if (x != -1) {
            top->right = new TreeNode(x);
            q.push(top->right);
        }
    }   

    return root;
}

void iterateTree(TreeNode *root, int level) {
    if (!root) return;
    std::string s;
    for (int i = 0; i < level; ++i) s += "  ";
    s += std::to_string(root->val);
    std::cout << s << std::endl;
    iterateTree(root->left, level+1);
    iterateTree(root->right, level+1);
}

int main() {
    TreeNode *p = buildTree();
    iterateTree(p, 0);

    Solution s;
    std::vector<double> ans = s.averageOfLevels(p);
    for (double val : ans) {
        std::cout << val << " ";
    }

    return 0;
}

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class Solution {
  int getMinimumDifference(TreeNode? root) {
    List<int> v = [];
    void dfs(TreeNode? p) {
        if (p == null) return;
        v.add(p.val);
        dfs(p.left); dfs(p.right);
    }
    dfs(root);
    v.sort();
    int res = v.last - v.first;
    for (int i = 1; i < v.length; ++i) {
        if (v[i] - v[i-1] < res) {
            res = v[i] - v[i-1];
            if (res == 0) break;
        }
    }
    return res;
  }
}

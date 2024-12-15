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
  int countNodes(TreeNode? root) {
    int cnt = 0;
    void dfs(TreeNode? p) {
        if (p == null) return;
        cnt++;
        dfs(p.left); dfs(p.right);
    }
    dfs(root);
    return cnt;
  }
}

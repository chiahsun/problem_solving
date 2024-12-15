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
  bool isSymmetric(TreeNode? root) {
    if (root == null) return true;
    bool dfs(TreeNode? p1, TreeNode? p2) {
        if (p1 == null && p2 == null) return true;
        if (p1 == null || p2 == null) return false;
        if (p1.val != p2.val) return false;
        return dfs(p1.left, p2.right) && dfs(p1.right, p2.left);
    }
    return dfs(root.left, root.right);
  }
}

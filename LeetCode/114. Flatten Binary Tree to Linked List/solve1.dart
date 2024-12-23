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
  void flatten(TreeNode? root) {
    if (root == null) return null;
    TreeNode dfs(TreeNode p) {
        if (p.left == null && p.right == null) {
            return p;
        } else if (p.left == null) {
            return dfs(p.right!);
        } else if (p.right == null) {
            TreeNode leaf = dfs(p.left!);
            p.right = p.left; p.left = null;
            return leaf;
        } else {
            TreeNode originalRight = p.right!;
            TreeNode leaf = dfs(p.right!);
            TreeNode leftLeaf = dfs(p.left!);
            p.right = p.left; p.left = null;
            leftLeaf.right = originalRight;
            return leaf;
        }
    }
    dfs(root!);
  }
}

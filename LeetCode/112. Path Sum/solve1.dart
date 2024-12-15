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
  bool hasPathSum(TreeNode? root, int targetSum) {
    bool dfs(TreeNode p, int prevSum) {
        prevSum += p.val;
        if (p.left == null && p.right == null) {
            return prevSum == targetSum;
        }
        return (p.left != null && dfs(p.left!, prevSum)) ||
            (p.right != null && dfs(p.right!, prevSum));
    }
    if (root == null) return false;
    return dfs(root, 0);
  }
}

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
  int maxPathSum(TreeNode? root) {
    int res = (root!).val;
    void dfs(TreeNode p) {
        if (p.left != null) dfs(p.left!);
        if (p.right != null) dfs(p.right!);
        int maxVal = p.val;
        if (p.left != null) maxVal = max(maxVal, p.val + (p.left!).val);
        if (p.right != null) maxVal = max(maxVal, p.val + (p.right!).val);
        res = max(res, p.val + (p.left != null ? (p.left!).val : 0) + (p.right != null ? (p.right!).val : 0));
        maxVal = max(0, maxVal);
        p.val = maxVal;
    }
    dfs(root!);

    return res;
  }
}

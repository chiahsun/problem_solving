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
    int res = 100000;
    List<int> dfs(TreeNode p) {
        var [a1, a2] = [p.val, p.val];
        if (p.left != null) {
            var [v1, v2] = dfs(p.left!);
            res = min(res, p.val - v2);
            a1 = v1;
        }
        if (p.right != null) {
            var [v1, v2] = dfs(p.right!);
            res = min(res, v1 - p.val);
            a2 = v2;
        }
        return [a1, a2];
    }
    dfs(root!);
    return res;
  }
}

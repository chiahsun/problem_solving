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
  List<int> rightSideView(TreeNode? root) {
    if (root == null) return [];
    List<int> res = [];
    void dfs(TreeNode p, int depth) {
        if (res.length == depth) res.add(p.val);
        else                     res[depth] = p.val;
        if (p.left != null) dfs(p.left!, depth+1);
        if (p.right != null) dfs(p.right!, depth+1);
    }
    dfs(root, 0);
    return res;
  }
}

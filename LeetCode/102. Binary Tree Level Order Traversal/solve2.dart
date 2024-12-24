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
  List<List<int>> levelOrder(TreeNode? root) {
    List<List<int>> res = [];
    List<TreeNode> cur = [], next = [];
    if (root != null) cur.add(root!);
    while (!cur.isEmpty) {
        List<int> curLevel = [];
        for (final a in cur) {
            curLevel.add(a.val);
            if (a.left != null) next.add(a.left!);
            if (a.right != null) next.add(a.right!);
        }
        res.add(curLevel);
        cur = next; next = [];
    };
    return res;
  }
}

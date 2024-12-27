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
  List<List<int>> zigzagLevelOrder(TreeNode? root) {
    if (root == null) return [];
    List<List<int>> res = [];
    List<TreeNode> q = [root], qNext = [];
    bool leftFirst = true;
    while (!q.isEmpty) {
        if (leftFirst) res.add(q.map((v) => v.val).toList());
        else res.add(q.reversed.map((v) => v.val).toList());
        for (final a in q) {
            final pLeft = a.left, pRight = a.right;
            if (pLeft != null) qNext.add(pLeft);
            if (pRight != null) qNext.add(pRight);
        }
        q = qNext; qNext = []; leftFirst = !leftFirst;
    }
    return res;
  }
}

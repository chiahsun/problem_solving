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
  List<double> averageOfLevels(TreeNode? root) {
    List<double> res = [];
    final List<List<TreeNode> > q = [[root!], []];
    int pos = 0;
    while (!q[pos].isEmpty) {
        int total = 0, cnt = 0;
        for (final p in q[pos]) {
            total += p.val;
            cnt++;
            if (p.left != null) q[1-pos].add(p.left!);
            if (p.right != null) q[1-pos].add(p.right!);
        }
        res.add(total / cnt);
        q[pos].clear();
        pos = 1 - pos;
    }
    return res;
  }
}

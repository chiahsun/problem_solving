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
  int maxDepth(TreeNode? root) {
    int res = 0;
    void findDepth(TreeNode p, int depth) {
        if (depth > res) res = depth;
        if (p.left != null) findDepth(p.left!, depth+1);
        if (p.right != null) findDepth(p.right!, depth+1);
    }
    if (root != null) findDepth(root, 1);
    return res;
  }
}

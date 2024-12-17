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
  int kthSmallest(TreeNode? root, int k) {
    List<int> dfs(TreeNode p, int offset) {
        if (p.left != null) {
            var [target, newOffset] = dfs(p.left!, offset);
            offset = newOffset;
            if (k <= offset) return [target, k];
        }
        offset += 1;
        if (offset == k) {
            return [p!.val, offset];
        }
        if (p.right != null) return dfs(p.right!, offset);
        else                 return [-1, offset];
    }

    return dfs(root!, 0)[0];
  }
}

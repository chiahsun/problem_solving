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
  int sumNumbers(TreeNode? root) {
    int total = 0;
    void dfs(TreeNode p, List<int> st) {
        st.add(p.val);
        if (p.left != null || p.right != null) {
            if (p.left != null) dfs(p.left!, st);
            if (p.right != null) dfs(p.right!, st);
        } else {
            int val = 0;
            for (final v in st) {
                val *= 10;
                val += v;
            }
            total += val;
        }
        st.removeLast();
    }
    List<int> st = [];
    if (root != null) dfs(root, st);
    return total;
  }
}

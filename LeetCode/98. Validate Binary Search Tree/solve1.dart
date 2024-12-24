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
  bool isValidBST(TreeNode? root) {
    List<int> dfs(TreeNode p) {
        int lMin = p.val, rMax = p.val;
        final pLeft = p.left, pRight = p.right;
        // https://stackoverflow.com/questions/65937353/equivalent-of-if-let-and-guard-let-of-swift-in-dart
        if (pLeft != null) {
            final [valid, minVal, maxVal] = dfs(pLeft);
            if (valid == 0) return [0, 0, 0];
            if (maxVal >= p.val) return [0, 0, 0];
            lMin = minVal;
        }
        if (pRight != null) {
            final [valid, minVal, maxVal] = dfs(pRight);
            if (valid == 0) return [0, 0, 0];
            if (minVal <= p.val) return [0, 0, 0];
            rMax = maxVal;
        }
        return [1, lMin, rMax];
    }
    return dfs(root!)[0] == 1;
  }
}

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
  TreeNode? sortedArrayToBST(List<int> nums) {
    final root = TreeNode();
    void dfs(TreeNode p, int begin, int end) {
        int M = begin + (end - begin) ~/ 2;
        p.val = nums[M];
        if (M > begin) {
            p.left = TreeNode();
            dfs(p.left!, begin, M);
        }
        if (end > M+1) {
            p.right = TreeNode();
            dfs(p.right!, M+1, end);
        }
    }

    dfs(root, 0, nums.length);
    return root;
  }
}

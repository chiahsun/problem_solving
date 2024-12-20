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
  TreeNode? buildTree(List<int> inorder, List<int> postorder) {
    if (inorder.isEmpty) return null;

    final root = postorder.last;
    final rootPos = inorder.indexWhere((v) => v == root);

    return TreeNode(
        root,
        buildTree(inorder.sublist(0, rootPos), postorder.sublist(0, rootPos)),
        buildTree(inorder.sublist(rootPos+1), postorder.sublist(rootPos, inorder.length-1))
    );
  }
}

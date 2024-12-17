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
  TreeNode? buildTree(List<int> preorder, List<int> inorder) {
    if (preorder.isEmpty) return null;
    int pos = 0;
    while (pos < inorder.length && inorder[pos] != preorder.first) pos++;
    return TreeNode(preorder.first,
                    buildTree(preorder.sublist(1, pos+1), inorder.sublist(0, pos)),
                    buildTree(preorder.sublist(pos+1), inorder.sublist(pos+1)));
  }
}

//    1
//  2   3
// 4 5 6 7
//
// 1 2 4 5 3 6 7
// 4 2 5 1 6 3 7

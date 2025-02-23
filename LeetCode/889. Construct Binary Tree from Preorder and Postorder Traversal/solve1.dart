//     1
//    / \
//   2   3
//  /     \
// 4       7
// 12437
// 42731
//
//     1.   // In code, we actually build it as right child
//    /
//   2
//  /
// 3
// 123
// 321
//     1
//       \
//       2
//      /
//     3
// 123
// 321

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
  TreeNode? constructFromPrePost(List<int> preorder, List<int> postorder) {
    if (preorder.isEmpty || preorder.length != postorder.length) return null;

    TreeNode construct(int preBegin, int preEnd, int postBegin, int postEnd) {
        final rootVal = preorder[preBegin], root = TreeNode(rootVal);
        if (preBegin+1 < preEnd) {
            final rightChildVal = postorder[postEnd-2];
            int cur = preEnd-1;
            while (preorder[cur] != rightChildVal) { --cur; }
            final rightSize = preEnd - cur;
            root.right = construct(cur, preEnd, postEnd-1-rightSize, postEnd-1);
            if (preBegin + 1 != cur) {
                root.left = construct(preBegin+1, cur, postBegin, postEnd-1-rightSize);
            }
        }
        return root;
    }

    final N = preorder.length;
    return construct(0, N, 0, N);
  }
}

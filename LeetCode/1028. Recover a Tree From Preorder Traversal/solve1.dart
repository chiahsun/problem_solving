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
  TreeNode? recoverFromPreorder(String traversal) {
    final st = <TreeNode>[], tokenSt = <String>[];
    for (int i = 0; i <= traversal.length; ++i) {
        int depth = 0, number = 0;
        if (i != traversal.length) {
            final c = traversal[i];
            if (c == "-") {
                if (!tokenSt.isEmpty && tokenSt.last != "-") {
                    number = int.parse(tokenSt.join(''));
                    tokenSt.clear();
                }
            } else {
                if (!tokenSt.isEmpty && tokenSt.last == "-") {
                    depth = tokenSt.length;
                    tokenSt.clear();
                }
            }
            tokenSt.add(c);
        } else {
            number = int.parse(tokenSt.join(''));
        }

        if (depth != 0) while (st.length > depth) st.removeLast();
        else if (number != 0) {
            final cur = TreeNode(number);
            if (st.isEmpty) st.add(cur);
            else {
                final parent = st.last;
                if (parent.left == null)  parent.left = cur;
                else                      parent.right = cur;
                st.add(cur);
            }
        }
    }
    return st.first;
  }
}

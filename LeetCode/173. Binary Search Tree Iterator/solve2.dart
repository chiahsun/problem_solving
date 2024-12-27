/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class BSTIterator {
  final List<TreeNode> st = [];

  BSTIterator(TreeNode? root) { addItandItsLefts(root); }

  void addItandItsLefts(TreeNode? p) {
    while (p != null) {
        st.add(p);
        p = p.left;
    }
  }

  int next() {
        final root = st.removeLast();
        final val = root.val;
        addItandItsLefts(root.right);
        return val;
  }

  bool hasNext() => !st.isEmpty;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = BSTIterator(root);
 * int param1 = obj.next();
 * bool param2 = obj.hasNext();
 */

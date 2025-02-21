/**
 * Definition for a binary tree node.
 * class TreeNode {
 *   int val;
 *   TreeNode? left;
 *   TreeNode? right;
 *   TreeNode([this.val = 0, this.left, this.right]);
 * }
 */
class FindElements {

  final Set<int> s = {};

  FindElements(TreeNode? root) {
    // https://dart.dev/language/operators#cascade-notation
    root?.val = 0;

    void traverse(TreeNode p) {
        s.add(p.val);
        TreeNode? pLeft = p.left, pRight = p.right;
        if (pLeft != null)  { pLeft.val = 2 * p.val + 1; traverse(pLeft); }
        if (pRight != null) { pRight.val = 2 * p.val + 2; traverse(pRight); }
    }

    if (root != null) traverse(root);
  }

  bool find(int target) => s.contains(target);
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = FindElements(root);
 * bool param1 = obj.find(target);
 */

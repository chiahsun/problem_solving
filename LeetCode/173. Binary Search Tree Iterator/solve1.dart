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
  final List<int> inorder = [];   
  int pos = 0;
  
  BSTIterator(TreeNode? root) {
    void inorderTraversal(TreeNode p) {
        final pLeft = p.left, pRight = p.right; 
        if (pLeft != null) inorderTraversal(pLeft);
         inorder.add(p.val);
        if (pRight != null) inorderTraversal(pRight);
    }
    if (root != null) inorderTraversal(root);
  }
  
  int next() => inorder[pos++];
  
  bool hasNext() => pos < inorder.length;
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = BSTIterator(root);
 * int param1 = obj.next();
 * bool param2 = obj.hasNext();
 */

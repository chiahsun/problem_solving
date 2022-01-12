/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    func insertIntoBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        if let root = root {
            let pnext = root.val > val ? root.left : root.right
            if let next = pnext {
                insertIntoBST(next, val)    
            } else {
                if (root.val > val) {
                    root.left = TreeNode(val)    
                } else {
                    root.right = TreeNode(val)    
                }
            }
            return root
        }
        return TreeNode(val)
    }
}
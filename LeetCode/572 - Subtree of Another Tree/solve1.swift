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
    func isSame(_ t1: TreeNode?, _ t2: TreeNode?) -> Bool {
        guard let t1 = t1, let t2 = t2 else { return t1 === t2 }
        if t1.val != t2.val { return false }
        return isSame(t1.left, t2.left) && isSame(t1.right, t2.right)
    }
    
    func isSubtree(_ root: TreeNode?, _ subRoot: TreeNode?) -> Bool {
        if isSame(root, subRoot) { return true }
        if let root = root {
            return  isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot)    
        }
        return false
    }
}
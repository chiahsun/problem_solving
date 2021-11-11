/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Solution {
    func isAncestor(_ root: TreeNode, _ val: Int) -> Bool {
        var p = root
        while p.val != val {
            if val > p.val { 
                guard let right = p.right else { return false }
                p = right
            } else {
                guard let left = p.left else { return false }
                p = left
            }
        }
        return true
    }
    
    func isAncestor(_ root: TreeNode, _ a: Int, _ b: Int) -> Bool {
        return isAncestor(root, a) && isAncestor(root, b)
    }
    
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        guard let root = root else { return nil }
        let a = p!.val
        let b = q!.val
        var cur = root
        
        while isAncestor(cur, a, b) {
            if let left = cur.left, isAncestor(left, a, b) {
                cur = left
            } else if let right = cur.right, isAncestor(right, a, b) {
                cur = right
            } else {
                return cur
            }
        }
        return nil
    }
}
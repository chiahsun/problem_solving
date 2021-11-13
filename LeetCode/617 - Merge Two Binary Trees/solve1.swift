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
    func merge(_ pa: TreeNode?, _ pb: TreeNode?) ->TreeNode? {
        if pa == nil && pb == nil { return nil }
        
        let va: Int = pa?.val ?? 0
        let vb: Int = pb?.val ?? 0
        
        let p = TreeNode(va + vb)
        p.left = merge(pa?.left, pb?.left)
        p.right = merge(pa?.right, pb?.right)
        return p
        
    }
    
    func mergeTrees(_ root1: TreeNode?, _ root2: TreeNode?) -> TreeNode? {
        return merge(root1, root2)
    }
}
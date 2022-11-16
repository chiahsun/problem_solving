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
    func traverse(_ root: TreeNode) -> (Bool, Int, Int) {
        var (min, max) = (root.val, root.val)
        if let left = root.left { 
            var (ok, lmin, lmax) = traverse(left)
            if !ok || lmax >= root.val { return (false, 0, 0) }
            min = lmin
        }
        if let right = root.right { 
            var (ok, rmin, rmax) = traverse(right)
            if !ok || rmin <= root.val { return (false, 0, 0) }
            max = rmax
        }
        return (true, min, max)
    }
    
    func isValidBST(_ root: TreeNode?) -> Bool {
        if let root = root {
            var (ok, _, _) = traverse(root)
            return ok
        }
        return true
    }
}
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
    func dfs(_ root: TreeNode) -> (Int, Int) {
        var la = 0
        var lb = 0
        var ra = 0
        var rb = 0
        if let left = root.left {
            (la, lb) = dfs(left) 
        }
        if let right = root.right {
            (ra, rb) = dfs(right) 
        }

        let b = la + ra
        return (max(root.val + lb + rb, b), b)
    }
    
    func rob(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        let (a, b) = dfs(root)
        return max(a, b)
    }
}
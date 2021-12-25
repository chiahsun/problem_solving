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
    func dfs(_ root: TreeNode, _ cur: Int, _ minNow: inout Int) {
        guard cur < minNow else { return }
        if root.left == nil && root.right == nil {
            minNow = min(minNow, cur)
            return
        }
        if let left = root.left { dfs(left, cur+1, &minNow) }
        if let right = root.right { dfs(right, cur+1, &minNow) }
    }
    
    func minDepth(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        var minNow = Int.max
        dfs(root, 1, &minNow)
        return minNow
    }
}
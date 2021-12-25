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
    func diameterOfBinaryTree(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        var ans = 0
        func dfs(_ root: TreeNode) -> Int {
            var llen = 0
            var rlen = 0
            if let left = root.left { llen = dfs(left) }
            if let right = root.right { rlen = dfs(right) }
            ans = max(ans, llen + rlen)
            return 1 + max(llen, rlen)
        }
        dfs(root)
        return ans
    }
}
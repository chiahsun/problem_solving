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
    func dfs(_ root: TreeNode?) -> (Int, Int) {
        guard let root = root else { return (0, 0) }
        let (s1, t1) = dfs(root.left)
        let (s2, t2) = dfs(root.right)
        return (s1 + s2 + root.val, t1 + t2 + abs(s2-s1))
    }

    func findTilt(_ root: TreeNode?) -> Int {
        dfs(root).1
    }
}
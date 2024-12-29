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
    func dfs(_ root: TreeNode, _ p: TreeNode) -> [TreeNode] {
        func dfs_helper(_ root: TreeNode, _ p: TreeNode, _ prefix: inout [TreeNode]) -> Bool {
            prefix.append(root)
            if root === p { return true }
            if let left = root.left, dfs_helper(left, p, &prefix) { 
                return true 
            }
            if let right = root.right, dfs_helper(right, p, &prefix) { 
                return true 
            }
            prefix.removeLast()
            return false
        }
        var prefix: [TreeNode] = []
        dfs_helper(root, p, &prefix)
        return prefix
    }
    
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        guard let root = root else { return nil }
        let (A, B) = (dfs(root, p!), dfs(root, q!)) 
        for i in stride(from: 1, to: min(A.count, B.count), by: 1) {
            if A[i] !== B[i] {
                return A[i-1]
            }
        }
        return A.count < B.count ? A.last! : B.last!
    }
}
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
    func dfs(_ cur: TreeNode, _ history: inout [TreeNode], _ prevSum: Int, _ targetSum: Int, _ ans: inout [[Int]]) {
        history.append(cur)
        defer { history.removeLast() }
        let curSum = prevSum + cur.val
        
        if cur.left == nil && cur.right == nil {
            if curSum == targetSum {
                ans.append(history.map { $0.val })
            }
            return 
        }

        if let left = cur.left { dfs(left, &history, curSum, targetSum, &ans) }
        if let right = cur.right { dfs(right, &history, curSum, targetSum, &ans) }
    }
    
    func pathSum(_ root: TreeNode?, _ targetSum: Int) -> [[Int]] {
        guard let root = root else { return [] }
        
        var ans: [[Int]] = []
        var history: [TreeNode] = []
        dfs(root, &history, 0, targetSum, &ans)
        return ans
    }
}
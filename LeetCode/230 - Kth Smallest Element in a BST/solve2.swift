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
    func dfs(_ root: TreeNode, _ leftCnt: inout Int) -> (Bool, Int) {
        if let left = root.left { 
            let res = dfs(left, &leftCnt) 
            if res.0 { return res }
        }
        if leftCnt == 1 {
            return (true, root.val)
        }
        leftCnt -= 1
        if let right = root.right {
            return dfs(right, &leftCnt) 
        }
        return (false, 0)
    }
    
    func kthSmallest(_ root: TreeNode?, _ k: Int) -> Int {
        guard let root = root else { return 0 }
        var leftCnt = k
        return dfs(root, &leftCnt).1
    }
}
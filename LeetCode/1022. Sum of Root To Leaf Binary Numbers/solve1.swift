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
    func sumRootToLeaf(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        var total = 0
        func dfs(_ cur: TreeNode, _ preVal: Int)  {
            let val = preVal*2 + cur.val
            if (cur.left == nil && cur.right == nil) {
                total += val
                return
            } 
                
            if let left = cur.left { dfs(left, val) }
            if let right = cur.right { dfs(right, val) }    
        }
        dfs(root, 0)
        return total
    }
}
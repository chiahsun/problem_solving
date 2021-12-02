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
    func getTreeSize(_ root: TreeNode) -> Int {
        var ans = 1
        if let left = root.left { ans += getTreeSize(left) }
        if let right = root.right { ans += getTreeSize(right) }
        return ans
    }
    
    func kthSmallest(_ root: TreeNode?, _ k: Int) -> Int {
        guard let root = root else { return 0 }
        
        var leftSize = 0
        if let left = root.left { 
            leftSize = getTreeSize(left) 
            if k <= leftSize { return kthSmallest(left, k) }
        }
        if (leftSize+1) == k { return root.val }
        
        guard let right = root.right else { return 0 } // Impossible if k <= n
        return kthSmallest(right, k - leftSize - 1)
    }
}
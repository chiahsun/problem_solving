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
    func rangeSumBST(_ root: TreeNode?, _ low: Int, _ high: Int) -> Int {
        guard let root = root else { return 0 }
        var ans = 0
        if root.val > low { 
            ans += rangeSumBST(root.left, low, high) 
        }
        if root.val < high { 
            ans += rangeSumBST(root.right, low, high) 
        }
        if root.val >= low && root.val <= high { 
            ans += root.val 
        }
        
        return ans
    }
}
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
    func maxAncestorDiff(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        
        var ans = 0
        func dfs(_ root: TreeNode) -> (Int, Int) {
            var minVal = root.val
            var maxVal = root.val
            if let left = root.left { 
                let (lmin, lmax) = dfs(left)
                minVal = min(minVal, lmin)
                maxVal = max(maxVal, lmax)
            }
            if let right = root.right { 
                let (rmin, rmax) = dfs(right)
                minVal = min(minVal, rmin)
                maxVal = max(maxVal, rmax)
            }
            ans = max(ans, maxVal - root.val)
            ans = max(ans, root.val - minVal)
            return (minVal, maxVal)
        }
        dfs(root)
        return ans
    }
}
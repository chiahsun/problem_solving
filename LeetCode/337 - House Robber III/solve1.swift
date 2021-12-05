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
//      4
//    1  null
//  2  null
//3

//        2
//     1     3 
// null 4

class Solution {
    func dfs(_ root: TreeNode) -> (Int, Int) {
        var leftTaken = 0
        var leftNotTaken = 0
        var rightTaken = 0
        var rightNotTaken = 0
        if let left = root.left {
            (leftTaken, leftNotTaken) = dfs(left) 
        }
        if let right = root.right {
            (rightTaken, rightNotTaken) = dfs(right) 
        }
        // print("root: \(root.val) sub not: \(leftNotTaken + rightNotTaken) sub: \(leftTaken + rightTaken)")
        
        return (root.val + leftNotTaken + rightNotTaken, max(leftTaken + rightTaken, leftNotTaken + rightNotTaken, leftTaken + rightNotTaken, leftNotTaken + rightTaken))
    }
    
    func rob(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        let (a, b) = dfs(root)
        return max(a, b)
    }
}
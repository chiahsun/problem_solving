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
    func preorder(_ ans: inout [Int], _ root: TreeNode) {
        ans.append(root.val)
        if let left = root.left { preorder(&ans, left) }
        if let right = root.right { preorder(&ans, right) }
    }
    
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        var ans: [Int] = []
        if let root = root {
            preorder(&ans, root)    
        }
        return ans
    }
}
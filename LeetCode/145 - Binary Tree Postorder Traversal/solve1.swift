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
    func postorder(_ ans: inout [Int], _ root: TreeNode) {
        if let left = root.left { postorder(&ans, left) }
        if let right = root.right { postorder(&ans, right) }
        ans.append(root.val)
    }
    
    func postorderTraversal(_ root: TreeNode?) -> [Int] {
        var ans: [Int] = []
        
        if let root = root {
            postorder(&ans, root)
        }
        return ans
    }
}
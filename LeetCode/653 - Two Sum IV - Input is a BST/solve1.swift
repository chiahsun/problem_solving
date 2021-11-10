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
    func findValue(_ root: TreeNode, _ value: Int) -> Bool {
        if value == root.val { return true }
        
        if value < root.val { 
            guard let left = root.left else { return false }
            return findValue(left, value) 
        }
        guard let right = root.right else { return false }
        return findValue(right, value)
    }
    
    func seek(_ root: TreeNode, _ cur: TreeNode, _ k: Int) -> Bool {
        if (cur.val + cur.val != k) && (findValue(root, k - cur.val)) { return true }
        if let left = cur.left, seek(root, left, k) { return true }
        if let right = cur.right, seek(root, right, k) { return true }
        return false
    }
    
    func findTarget(_ root: TreeNode?, _ k: Int) -> Bool {
        guard let root = root else { return false }
        return seek(root, root, k)
    }
}
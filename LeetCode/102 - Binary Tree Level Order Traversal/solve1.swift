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
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        var q: [TreeNode] = []
        var ans: [[Int]] = []
        if let root = root { q.append(root) }
        
        while !q.isEmpty {
            var curQ = q
            q = []
            
            var cur: [Int] = []
            while !curQ.isEmpty {
                let a = curQ.removeFirst()
                cur.append(a.val)
                if let left = a.left { q.append(left) }
                if let right = a.right { q.append(right) }
            }
            ans.append(cur)
        }
        return ans
    }
}
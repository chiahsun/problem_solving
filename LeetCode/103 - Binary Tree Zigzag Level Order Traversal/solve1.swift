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
    func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
        guard let root = root else { return [] }
        
        var q: [TreeNode] = [root]
        var qNext: [TreeNode] = []
        var fromLeft = true
        var ans: [[Int]] = []
        while !q.isEmpty {
            var cur: [Int] = []
            while let last = q.popLast() {
                cur.append(last.val)
                if fromLeft {
                    if let left = last.left { qNext.append(left) }     
                    if let right = last.right { qNext.append(right) } 
                   
                } else {
                    if let right = last.right { qNext.append(right) } 
                    if let left = last.left { qNext.append(left) }       
                }
            }
            ans.append(cur)
            q = qNext
            fromLeft = !fromLeft
            qNext.removeAll()
        }
        return ans
    }
}

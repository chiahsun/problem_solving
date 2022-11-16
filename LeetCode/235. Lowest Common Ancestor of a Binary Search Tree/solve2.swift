/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Solution {
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        guard var cur = root else { return nil }
        let (a, b) = (p!.val, q!.val)

        while true {
            if cur.val > a && cur.val > b { 
                guard let left = cur.left else { return nil }
                cur = left 
            } else if cur.val < a && cur.val < b {
                guard let right = cur.right else { return nil }
                cur = right
            } else {
                return cur
            }
        }
        return nil
    }
}
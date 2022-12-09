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
    func dfs(_ cur: TreeNode?, _ depth: Int, _ ans: inout [Int]) {
        guard let cur = cur else { return }
        if depth < ans.count { ans[depth] = cur.val }
        else                 { ans.append(cur.val) }
        dfs(cur.left, depth+1, &ans)
        dfs(cur.right, depth+1, &ans)
    }
    
    func rightSideView(_ root: TreeNode?) -> [Int] {
        var ans: [Int] = []
        dfs(root, 0, &ans)
        return ans
    }
}
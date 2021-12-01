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
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        guard !preorder.isEmpty else { return nil }
        
        let root = preorder[0]
        var leftSize = 0
        while leftSize < inorder.count {
            if inorder[leftSize] == root { break }
            leftSize += 1
        }
        return TreeNode(
            root, 
            buildTree(Array(preorder[1..<(1+leftSize)]), Array(inorder[0..<leftSize])),
            buildTree(Array(preorder[(1+leftSize)..<(preorder.count)]), Array(inorder[(leftSize+1)..<inorder.count]))
        )
    }
}
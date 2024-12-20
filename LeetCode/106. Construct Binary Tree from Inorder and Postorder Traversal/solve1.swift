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

//     3
//    / \
//   9   20
//  / \
// 1  2
//
// 1 9 2 3 29
// 1 2 9 29 3
class Solution {
    func buildTree(_ inorder: [Int], _ postorder: [Int]) -> TreeNode? {
        guard inorder.count > 0 else { return nil }
        
        let root = postorder.last!
        var rootPos = 0
        for i in 0..<inorder.count {
            if inorder[i] == root {
                rootPos = i
                break
            }
        }
        
        let left = buildTree(Array(inorder[0..<rootPos]), Array(postorder[0..<rootPos]))
        let right = buildTree(Array(inorder[rootPos+1..<inorder.count]), Array(postorder[rootPos..<rootPos+(inorder.count-rootPos-1)]))
                              
        return TreeNode(root, left, right)
    }
}
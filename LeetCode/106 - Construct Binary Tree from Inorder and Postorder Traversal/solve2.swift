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
    func build(_ inorder: ArraySlice<Int>, _ postorder: ArraySlice<Int>) -> TreeNode? {
        guard inorder.count > 0 else { return nil }
        
        let root = postorder.last!
        var rootPos = 0
        for i in inorder.startIndex..<inorder.endIndex {
            if inorder[i] == root {
                rootPos = i
                break
            }
        }

        let left = build(inorder[inorder.startIndex..<rootPos], postorder[postorder.startIndex..<postorder.startIndex+(rootPos-inorder.startIndex)])
        let right = build(inorder[rootPos+1..<inorder.endIndex], postorder[postorder.startIndex+(rootPos-inorder.startIndex)..<postorder.startIndex+(rootPos-inorder.startIndex)+(inorder.endIndex-rootPos-1)])
        return TreeNode(root, left, right)
    }
    
    func buildTree(_ inorder: [Int], _ postorder: [Int]) -> TreeNode? {
        return build(ArraySlice(inorder), ArraySlice(postorder))
    }
}
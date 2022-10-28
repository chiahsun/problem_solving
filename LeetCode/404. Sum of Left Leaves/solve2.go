/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isLeaf(root *TreeNode) bool {
    return root != nil && root.Left == nil && root.Right == nil
}

func sumOfLeftLeaves(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    sum := 0
    if isLeaf(root.Left) {
        sum += root.Left.Val
    } else {
        sum += sumOfLeftLeaves(root.Left)
    }
    if !isLeaf(root.Right) {
        sum += sumOfLeftLeaves(root.Right)
    }
    return sum
}

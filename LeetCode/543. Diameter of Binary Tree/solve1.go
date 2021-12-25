/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    if root == nil {
        return 0
    }
    ans := max(getDepth(root.Left) + getDepth(root.Right), diameterOfBinaryTree(root.Left))
    return max(ans, diameterOfBinaryTree(root.Right))
}

func getDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    return max(getDepth(root.Left), getDepth(root.Right)) + 1;
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

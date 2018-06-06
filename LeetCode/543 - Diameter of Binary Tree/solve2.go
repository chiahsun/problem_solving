/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    d, _ := diameterHelper(root)
    return d
}

// Diameter, height
func diameterHelper(root *TreeNode) (int, int) {
    if root == nil {
        return 0, 0
    }
    
    d1, h1 := diameterHelper(root.Left)
    d2, h2 := diameterHelper(root.Right)
    d := max(max(h1 + h2, d1), d2)
    
    return d, max(h1, h2) + 1    
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}


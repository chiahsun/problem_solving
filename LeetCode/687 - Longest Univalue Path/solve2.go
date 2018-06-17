/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestUnivaluePath(root *TreeNode) int {
    _, longestPath := longestRec(root)
    
    return longestPath
}

func longestRec(root *TreeNode) (depth, longestPath int) {
    if root == nil {
        return
    }
    
    d1, lp1 := longestRec(root.Left)
    d2, lp2 := longestRec(root.Right)
    
    l, r := 0, 0
    if root.Left != nil && root.Left.Val == root.Val {
        l = 1+d1
    }
    if root.Right != nil && root.Right.Val == root.Val {
        r = 1+d2
    }
    depth = max(l, r)
    longestPath = max(max(lp1, lp2), l+r)
    return
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

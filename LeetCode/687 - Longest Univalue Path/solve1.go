/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestUnivaluePath(root *TreeNode) int {
    ans := 0
    
    var longestRec func(*TreeNode)
    longestRec = func(root *TreeNode) {
        if root == nil {
            return
        }
    
        ans = fmax(ans, findDepth(root.Left, root.Val) + findDepth(root.Right, root.Val))
    
        longestRec(root.Left)
        longestRec(root.Right)
    }
    
    longestRec(root)
    return ans
}

func findDepth(root *TreeNode, val int) int {
    if root == nil || root.Val != val {
        return 0
    }
    
    return 1 + fmax(findDepth(root.Left, val), findDepth(root.Right, val))
}

func fmax(a, b int) int {
    if a > b {
        return a
    }
    return b
}

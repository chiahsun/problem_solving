/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubtree(s *TreeNode, t *TreeNode) bool {
    if s == t {
        return true
    }
    if s == nil {
        return false
    }
    return isIdentical(s, t) || isSubtree(s.Left, t) || isSubtree(s.Right, t)
}

func isIdentical(s *TreeNode, t *TreeNode) bool {
    if s == nil && t == nil {
        return true
    }
    if s == nil || t == nil {
        return false
    }
    
    if s.Val != t.Val {
        return false
    }
    
    return isIdentical(s.Left, t.Left) && isIdentical(s.Right, t.Right)
}

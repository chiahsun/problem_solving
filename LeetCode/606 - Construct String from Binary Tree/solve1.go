/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func tree2str(t *TreeNode) string {
    if t == nil {
        return ""
    }
    if t.Left == nil && t.Right == nil {
        return fmt.Sprintf("%d", t.Val)
    }   
    leftstr := tree2str(t.Left)
    rightstr := tree2str(t.Right)
    if t.Right == nil {
        return fmt.Sprintf("%d(%s)", t.Val, leftstr)
    }
    return fmt.Sprintf("%d(%s)(%s)", t.Val, leftstr, rightstr)
}

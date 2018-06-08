/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {
    min, ans := root.Val, -1
    
    findRec(root, &ans, &min)
    return ans
}

func findRec(root *TreeNode, ans *int, min *int) {
    if root == nil {
        return
    }
    
    if root.Val == *min {
        findRec(root.Left, ans, min)
        findRec(root.Right, ans, min)
    } else {
        if *ans == -1 || root.Val < *ans {
            *ans = root.Val
        }
    }
}

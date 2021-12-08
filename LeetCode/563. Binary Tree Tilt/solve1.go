/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findTilt(root *TreeNode) int {
    _, ans := findRec(root)
    return ans
}

func abs(a int) int {
    if a >= 0 {
        return a
    }
    return -a
}

// (sum, totalTilt)
func findRec(root *TreeNode) (int, int) {
    if root == nil {
        return 0, 0
    }
    suml, tiltl := findRec(root.Left)
    sumr, tiltr := findRec(root.Right)
    return suml+sumr+root.Val, abs(suml - sumr)+tiltl+tiltr
}

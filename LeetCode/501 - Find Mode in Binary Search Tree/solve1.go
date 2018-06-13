/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findMode(root *TreeNode) []int {
    m := make(map[int]int)
    findRec(root, m)
    
    maxCount := 0
    ans := make([]int, 0)
    for k, v := range m {
        if v > maxCount {
            maxCount = v
            ans = []int{k}
        } else if v == maxCount {
            ans = append(ans, k)
        }
    }
    return ans
}


func findRec(root *TreeNode, m map[int]int) {
    if root == nil {
        return
    }
    
    m[root.Val]++
    findRec(root.Left, m)
    findRec(root.Right, m)
}

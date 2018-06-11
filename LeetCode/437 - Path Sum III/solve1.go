/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, sum int) int {
    ans := 0
    m := make(map[int]int)
    pathSumRec(root, &ans, m, sum)
    return ans
}

func pathSumRec(cur *TreeNode, ans *int, m map[int]int, sum int) {
    if cur == nil {
        return
    }
    
    if m[sum - cur.Val] != 0 {
        // fmt.Println("Cur ", cur.Val, " add ", m[sum - cur.Val], " for ", sum - cur.Val, " m:", m)
        *ans += m[sum - cur.Val]
    }
    if cur.Val == sum {
        // fmt.Println("Cur ", cur.Val, " add ", 1, " for sum directly ", sum, " m:", m)
        *ans += 1
    }
    next := make(map[int]int)
    for k, v := range m {
        next[k+cur.Val] += v
    }
    next[cur.Val]++
    
    pathSumRec(cur.Left, ans, next, sum)
    pathSumRec(cur.Right, ans, next, sum)
}

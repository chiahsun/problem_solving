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
    preSums := make([]int, 0)
    pathSumRec(root, &ans, &preSums, sum)
    return ans
}

func pathSumRec(cur *TreeNode, ans *int, preSums *[]int, sum int) {
    if cur == nil {
        return
    }
    
    for i := 0; i < len(*preSums); i++ {
        total := cur.Val + (*preSums)[i]
        if total == sum {
            *ans++
        }
        (*preSums)[i] = total
    }
    if cur.Val == sum {
        *ans++
    }
    *preSums = append(*preSums, cur.Val)
    
    pathSumRec(cur.Left, ans, preSums, sum)
    pathSumRec(cur.Right, ans, preSums, sum)
    for i := 0; i < len(*preSums); i++ {
        (*preSums)[i] -= cur.Val
    }
    *preSums = (*preSums)[:len(*preSums)-1]
}

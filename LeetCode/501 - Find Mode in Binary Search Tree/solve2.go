/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findMode(root *TreeNode) []int {
    
    var getCount func(root *TreeNode, target int) int
    getCount = func(root *TreeNode, target int) int {
        if root == nil {
            return 0
        }
        
        cnt := 0
        if root.Val == target {
            cnt++
        }
        return cnt + getCount(root.Left, target) + getCount(root.Right, target)
    }
    
    maxCount := 0
    ans := make([]int, 0)
    
    var findRec func(root *TreeNode)
    findRec = func(root *TreeNode) {
        if root == nil {
            return
        }
        cnt := getCount(root, root.Val)
        // fmt.Println("Get count for val ", root.Val, " with count ", cnt)
        if cnt > maxCount {
            maxCount = cnt
            ans = []int{root.Val}
        } else if cnt == maxCount {
            ans = append(ans, root.Val)
        }
        findRec(root.Left)
        findRec(root.Right)
    }
    
    findRec(root)
    
    return ans
}




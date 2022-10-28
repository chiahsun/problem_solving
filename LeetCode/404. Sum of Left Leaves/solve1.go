/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumRec(root *TreeNode) (int, bool) {
    if root == nil {
        return 0, true
    }
    
    if root.Left == nil && root.Right == nil {
        return root.Val, true
    }
    
    val1, _ := sumRec(root.Left)
    val2, isLeaf2 := sumRec(root.Right)
    
    if isLeaf2 {
        return val1, false
    } else {
        return val1 + val2, false   
    }
}

func sumOfLeftLeaves(root *TreeNode) int {
    if root == nil {
        return 0
    }
    
    ans, isLeaf := sumRec(root)
    if isLeaf {
        return 0
    } else {
        return ans
    }
}

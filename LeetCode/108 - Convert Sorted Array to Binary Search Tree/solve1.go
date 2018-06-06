/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
    return buildTree(nums, 0, len(nums)-1)
}

func buildTree(nums []int, lo int, hi int) *TreeNode {
    if lo > hi {
        return nil
    }
    
    mid := (lo+hi)/2
    left := buildTree(nums, lo, mid-1)
    right := buildTree(nums, mid+1, hi)
    root := TreeNode{Val: nums[mid], Left: left, Right: right}
    
    return &root
}

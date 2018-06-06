func maximumProduct(nums []int) int {
    N := len(nums)
    sort.Ints(nums)
    a, b := nums[0]*nums[1]*nums[N-1], nums[N-3]*nums[N-2]*nums[N-1]
    return max(a, b)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

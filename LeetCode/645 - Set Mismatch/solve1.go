func findErrorNums(nums []int) []int {
    sort.Ints(nums)
    
    last := 0
    ans := make([]int, 2)
    ans[1] = 1
    for i := 0; i < len(nums); i++ {
        cur := nums[i]
        if cur == last {
            ans[0] = last
        }
        last = cur
        
        if ans[1] == cur {
            ans[1]++
        }
    }
    return ans
}

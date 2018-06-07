func findLengthOfLCIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    
    last, cur_len, ans := nums[0], 1, 1
    
    for i := 1; i < len(nums); i++ {
        cur := nums[i]
        if cur > last {
            last = cur
            cur_len++
        } else {
            last = cur
            cur_len = 1
        }
        if cur_len > ans {
            ans = cur_len
        }
    }
    return ans
}

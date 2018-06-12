func findErrorNums(nums []int) []int {
    ans := make([]int, 2)
    for i := 0; i < len(nums); i++ {
        if i+1 != nums[i] {
            pos := i
            for nums[pos] != pos+1 {
                val := nums[pos]
                target_pos := val-1
                if nums[target_pos] == val {
                    ans[0] = val
                    ans[1] = pos+1
                    break
                }
                nums[pos], nums[target_pos] = nums[target_pos], nums[pos]
            }
        }
    }
    
    return ans
}

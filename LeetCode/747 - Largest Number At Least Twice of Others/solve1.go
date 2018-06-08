func dominantIndex(nums []int) int {
    if len(nums) == 1 {
        return 0
    }
    
    p, q := 0, 1
    if nums[p] < nums[q] {
        p, q = q, p
    }
    
    for i := 2; i < len(nums); i++ {
        cur := nums[i]
        if cur > nums[q] {
            q = i
        }
        if nums[p] < nums[q] {
            p, q = q, p
        }
    }
    
    if nums[p] >= nums[q]*2 {
        return p
    }
    return -1
}

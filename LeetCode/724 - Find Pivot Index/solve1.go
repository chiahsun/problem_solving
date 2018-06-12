func pivotIndex(nums []int) int {
    totalsum := get_total(nums)

    presum := 0
    ans := -1
    for i := range nums {
        cur := nums[i]
        
        if presum == totalsum - cur - presum {
            ans = i
            break    
        }
        presum += cur
    }
    return ans
}

func get_total(nums []int) int {
    total := 0
    for _, v := range nums {
        total += v
    }
    return total
}

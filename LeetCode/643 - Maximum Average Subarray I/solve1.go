func findMaxAverage(nums []int, k int) float64 {
    sum := 0
    for i := 0; i < k; i++ {
        sum += nums[i]
    }
    max_sum := sum
    for i := k; i < len(nums); i++ {
        sum += nums[i]
        sum -= nums[i-k]
        if max_sum < sum {
            max_sum = sum
        }
    }
    
    return float64(max_sum)/float64(k)
}

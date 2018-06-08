func findLHS(nums []int) int {
    m := make(map[int]int)
    
    for _, v := range nums {
        m[v]++
    }
    
    ans := 0
    for k, v := range m {
        if m[k+1] != 0 {
            sum :=  v+m[k+1]
            if sum > ans {
                ans = sum
            }
        }
    }
    return ans
} 

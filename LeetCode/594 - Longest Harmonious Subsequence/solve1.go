func findLHS(nums []int) int {
    m := make(map[int]int)
    
    for _, v := range nums {
        m[v]++
    }
    
    ans := 0
    for k, v := range m {
        if m[k+1] != 0 {
            ans = max(ans, v+m[k+1])
        }
        if m[k-1] != 0 {
            ans = max(ans, v+m[k-1])
        }
    }
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

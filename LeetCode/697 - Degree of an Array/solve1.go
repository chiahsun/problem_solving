func getMaxFreqElements(nums []int) map[int]bool {
    max_freq := 0
    freq := make(map[int]int)
    for _, v := range nums {
        _, ok := freq[v]
        if ok {
            freq[v]++
        } else {
            freq[v] = 1
        }
        if freq[v] > max_freq {
            max_freq = freq[v]
        }
    }
    elems := make(map[int]bool)
    for k, v := range freq {
        if v == max_freq {
            elems[k] = true
        }
    }
    return elems
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}
func findShortestSubArray(nums []int) int {
    elems := getMaxFreqElements(nums)
    
    begins := make(map[int]int)
    ends := make(map[int]int)
    
    for i, v := range nums {
        _, isMaxFreq := elems[v]
        
        if isMaxFreq {
            _, ok := begins[v]
            if !ok {
                begins[v] = i
            }
        
            ends[v] = i
        }
    }
    
    ans := len(nums)
    for k, v := range begins {
        ans = min(ans, ends[k] - v + 1)
    }
    return ans
}

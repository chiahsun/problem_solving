func findAnagrams(s string, p string) []int {
    N := len(p)
    if len(s) < N {
        return []int{}
    }
    
    unmatched := 0
    countp := make([]int, 26)
    for _, c := range p {
        cur := int(c) - int('a')
        if countp[cur] == 0 {
            unmatched++
        }
        countp[cur]++
    }
    
    ans := make([]int, 0)
    count := make([]int, 26)
    for i := 0; i < len(s); i++ {
        cur := int(s[i]) - int('a')
        if count[cur] == countp[cur] {
            unmatched++
            count[cur]++
        } else {
            count[cur]++
            if count[cur] == countp[cur] {
                unmatched--
            }
        }
        
        if i-N >= 0 {
            cur := int(s[i-N]) - int('a')
            if count[cur] == countp[cur] {
                unmatched++
                count[cur]--
            } else {
                count[cur]--
                if count[cur] == countp[cur] {
                    unmatched--
                }
            }
        }
        if unmatched == 0 {
            ans = append(ans, i-N+1)
        }
    }
    return ans
}

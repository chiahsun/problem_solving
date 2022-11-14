func longestPalindrome(s string) int {
    m := make(map[rune]int)
    
    for _, c := range s {
        _, ok := m[c]
        if ok {
            m[c]++
        } else {
            m[c] = 1
        }
    }
    
    hasSingle := false
    ans := 0
    
    for _, v := range m {
        ans += (v/2)*2
        hasSingle = hasSingle || (v % 2 != 0)
    }
    if hasSingle {
        ans += 1
    }
    
    return ans
}

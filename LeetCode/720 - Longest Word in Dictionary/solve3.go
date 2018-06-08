func longestWord(words []string) string {
    sort.Strings(words)
    
    ans := ""
    m := make(map[string]bool)
    for _, wd := range words {
        if len(wd) == 1 || m[wd[:len(wd)-1]] {
            m[wd] = true
            if len(wd) > len(ans) {
                ans = wd
            }
        }
    }
    return ans
}

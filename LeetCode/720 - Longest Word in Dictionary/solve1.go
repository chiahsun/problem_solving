func longestWord(words []string) string {
    sort.Slice(words, func(i, k int) bool {
        return len(words[i]) < len(words[k])
    })
    
    m := make(map[string]bool)
    ans := words[0]
    for _, wd := range words {
        ok := false
        if len(wd) == 1 {
            m[wd] = true
            ok = true
        } else {
            if len(wd) > len(ans)+1 {
                break
            }
            
            _, found := m[wd[:len(wd)-1]]
            if found {
                m[wd] = true
                ok = true
            }
        }
        
        if ok && (len(wd) > len(ans) || (len(wd) == len(ans) && wd < ans)) {
            ans = wd
        }
    }
    
    return ans
}

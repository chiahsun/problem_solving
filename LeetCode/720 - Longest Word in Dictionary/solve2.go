func longestWord(words []string) string {
    sort.Slice(words, func(i, k int) bool {
        a, b := words[i], words[k]
        na, nb := len(a), len(b)
        if na != nb {
            return na < nb
        }
        return a < b
    })
    
    m := make(map[string]bool)
    ans := words[0]
    for _, wd := range words {
        ok := false
        if len(wd) == 1 {
            m[wd], ok = true, true
        } else {
            if len(wd) > len(ans)+1 {
                break
            }
            
            _, found := m[wd[:len(wd)-1]]
            if found {
                m[wd], ok = true, true
            }
        }
        
        if ok && len(wd) > len(ans) {
            ans = wd
        }
    }
    
    return ans
}

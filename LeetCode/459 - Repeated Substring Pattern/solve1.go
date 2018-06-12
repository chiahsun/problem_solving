func repeatedSubstringPattern(s string) bool {
    for i := 1; i <= len(s)/2; i++ {
        if len(s) % i == 0 {
            ok := true 
            for k := i; k < len(s); k += i {
                for p, q := 0, k; p < i; {
                    if s[p] != s[q] {
                        ok = false
                        break
                    }
                    p++
                    q++
                }
            }
            if ok {
                return true
            }
        }
    }
    return false
}

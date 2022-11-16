func repeatedSubstringPattern(s string) bool {
    for i := 1; i <= len(s)/2; i++ {
        if len(s) % i == 0 {
            ok := true 
            for k := 0; k < i && ok; k++ {
                first := s[k]
                for pos := k+i; pos < len(s); pos += i {
                    if s[pos] != first {
                        ok = false
                        break
                    }
                }
            }
            
            if ok {
                return true
            }
        }
    }
    return false
}

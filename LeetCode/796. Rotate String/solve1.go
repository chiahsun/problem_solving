func rotateString(A string, B string) bool {
    if len(A) != len(B) {
        return false
    }
    if len(A) == 0 && len(B) == 0 {
        return true
    }
    
    C := []byte(A)
    C = append(C[:], C[:]...)
    
    for i := 0; i < len(B); i++ {
        p, q := i, len(B)-1+i
        ok := true
        for p <= q {
            if C[p] != B[p-i] || C[q] != B[q-i] {
                ok = false
                break
            }
            p++
            q--
        }
        if ok {
            return true
        }
    }
    return false
}

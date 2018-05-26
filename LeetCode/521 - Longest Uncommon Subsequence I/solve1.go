func Max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func findLUSlength(a string, b string) int {
    if len(a) != len(b) {
        return Max(len(a), len(b))
    }
    
    for i := 0; i < len(a); i++ {
        if a[i] != b[i] {
            return len(a)
        }
    }
    return -1
}

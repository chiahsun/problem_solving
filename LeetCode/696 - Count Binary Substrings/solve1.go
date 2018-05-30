func countBinarySubstrings(s string) int {
    N := len(s)
    count := 0
    for i := 0; i < N-1; i++ {
        if s[i] != s[i+1] {
            p, q := i, i+1
            tailp := s[p]
            headq := s[q]
            for ;p >= 0 && q < N && s[p] == tailp && s[q] == headq; {
                count++
                p--
                q++
            }
        }
    }
    return count
}

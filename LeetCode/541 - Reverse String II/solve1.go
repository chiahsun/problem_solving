func reverseStr(s string, k int) string {
    A := []rune(s)
    incr := 2 * k
    for begin := 0; begin < len(s); begin += incr {
        p, q := begin, min(begin+k-1, len(s)-1)
        for p < q {
            A[p], A[q] = A[q], A[p]
            p++
            q--
        }
    }
    return string(A)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

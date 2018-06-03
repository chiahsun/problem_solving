func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func maxCount(m int, n int, ops [][]int) int {
    a, b := m, n
    for i := 0; i < len(ops); i++ {
        op := ops[i]
        a = min(a, op[0])
        b = min(b, op[1])
    }
    return a * b
}

var m = map[int]int{
    0: 0,
    1: 1,
    8: 8,
    2: 5,
    5: 2,
    6: 9,
    9: 6,
}

func isGood(N int) bool {
    changed := false
    for N > 0 {
        a := N % 10
        rotated, ok := m[a]
        if !ok {
            return false
        }
        if !changed && rotated != a {
            changed = true
        }
        
        N /= 10
    }
    return changed
}

func rotatedDigits(N int) int {
    count := 0
    for i := 1; i <= N; i++ {
        if isGood(i) {
            count++
        }
    }
    return count
}

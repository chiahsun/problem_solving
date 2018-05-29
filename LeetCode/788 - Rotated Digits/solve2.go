// 1: good, 0: normal, -2: invalid
func isGood(N int) int {
    m := []int{0, 0, 1, -2, -2, 1, 1, -2, 0, 1}
    if N < 10 {
        return m[N]
    }
        
    a := isGood(N%10) 
    b := isGood(N/10)
    c := a + b
    switch {
        case c < 0: return -2
        case c == 0: return 0
        case c > 0: return 1
    }
    return 0 // won't happen
}

func rotatedDigits(N int) int {
    count := 0
    for i := 1; i <= N; i++ {
        if isGood(i) > 0{
            count++
        }
    }
    return count
}

// 1: good, 0: normal, -2: invalid
func isGood(N int, A *[]int) int {
    if (*A)[N] != -1 {
        return (*A)[N]
    }
    
    m := []int{0, 0, 1, -2, -2, 1, 1, -2, 0, 1}
    if N < 10 {
        (*A)[N] = m[N]
    } else {
        c := isGood(N%10, A)  + isGood(N/10, A)
        switch {
            case c < 0: (*A)[N] = -2
            case c == 0: (*A)[N] = 0
            case c > 0: (*A)[N] = 1
        }
    }
    return (*A)[N]
}

func rotatedDigits(N int) int {
    count := 0
    A := make([]int, N+1)
    for i := 0; i <= N; i++ {
        A[i] = -1
    }
    for i := 1; i <= N; i++ {
        if isGood(i, &A) > 0{
            count++
        }
    }
    return count
}

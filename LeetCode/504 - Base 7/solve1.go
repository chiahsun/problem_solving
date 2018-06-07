func convertToBase7(num int) string {
    if num < 0 {
        return "-" + convertToBase7(-num)
    }
    
    const N = 7
    A := make([]rune, 0)
    for num > 0 {
        A = append(A, rune(int('0') + num % N))
        num /= N
    }
    if len(A) == 0 {
        A = append(A, '0')
    }
    reverse(A)
    return string(A)
}

func reverse(a []rune) {
    for i, k := 0, len(a)-1; i < k; {
        a[i], a[k] = a[k], a[i]
        i++
        k--
    }
}
